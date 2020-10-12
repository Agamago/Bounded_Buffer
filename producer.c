/*
 * Joey Sheridan
 * csheridan@chapman.edu
 * Operating Systems Assignment #3
 * Bounded_Buffer
 * producer.c
 *
 */
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MMAP_SIZE   4096
#define BUFFER_SIZE 100
#define PAYLOAD_SIZE 34
const int MMPAP_SIZE = 4096;

unsigned int ip_checksum(char *data, int length);
typedef struct items{
   int    item_no;		/* number of the item produced */
   unsigned short cksum;        /* 16-bit Internet checksum    */
   unsigned char payload[PAYLOAD_SIZE];  /* random generated data */
 } item;

int main(int argc, char *argv[]) {

  const char *name = argv[1];
  int i, shm_fd;
  int nbytes;
  void *ptr;
  unsigned short cksum;
  char *buffers;
  nbytes = atoi(argv[1]);

  shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
  if (shm_fd == -1) {
	  perror("error creating shared memory");
	  return -1;
  }
  ftruncate(shm_fd, MMAP_SIZE);
  ptr = mmap(0, MMAP_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
  buffers = (char *)ptr;
  for (i = 0 ; i < nbytes ;i++) {
	  buffers[i] = (unsigned char) rand() % 256;
  }
  //cksum = (unsigned short) ip_checksum(&buffer[0], nbytes);
  //memcpy((void *)&buffer[nbytes], &cksum, sizeof(cksum));

  item buffer[BUFFER_SIZE];
  int    in  = 0;
  int    out = 0;
  item next_produced;

  while (true) {
	/* produce an item in next_produced */
	/* 1. Increment the buffer count (item_no)  */
	++ next_produced.item_no;
	/* 2. Calculate the 16-bit checksum (cksum) */

	next_produced.cksum = ip_checksum(argv[1], strlen(argv[1]));
	printf("CheckSum :0x%x (%s) \n",next_produced.cksum, name);

	/* 3. Generate the payload data*/
	
	
	next_produced.payload[*argv[1]] = (unsigned char) rand() % 256;  
	while (((in + 1) % BUFFER_SIZE) == out) {      
		sleep(1); /* do nothing but sleep for 1 second */
	}
	cksum = (unsigned short) ip_checksum(&buffers[0], nbytes);
	memcpy((void *)&buffer[nbytes], &cksum, sizeof(cksum));

	    buffer[in] = next_produced; /* store next_produced into shared
	   					   buffer */                      
	    in = (in + 1) % BUFFER_SIZE;
  }
}



//CHECKSUM PROCESS
unsigned int ip_checksum(char *data, int length) 
{	    
  unsigned int sum = 0xffff;
  unsigned short word; 
  int  i;
  // Handle complete 16-bit blocks.
  for (i = 0; i+1<length; i+=2) {
	 memcpy(&word, data+i, 2);			
	 sum += word;		
	 if (sum > 0xffff) {			
		 sum -= 0xffff;			
	 }		
  } 
  // Handle any partial block at the end of the data.
  if (length&1) {			
	word=0;			
	memcpy(&word, data+length-1, 1);			
	sum += word;;		
	if (sum > 0xffff) {		
		sum -= 0xffff;			
	}			
  }
  // Return the checksum
  return ~sum;
}
