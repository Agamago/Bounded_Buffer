/* Joey Sheridan
 * csheridan@chapman.edu
 * Operating Systems
 * Assignment #3
 * consumer.c
 *
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#define NMAP_SIZE   4096
#define BUFFER_SIZE 100
#define PAYLOAD_SIZE 34

void sig_handler(int sig) {
	printf("%s:: Got the Signal %d \n", __FUNCTION__, sig);
}


typedef struct {
    int    item_no;		/* number of the item produced */
    unsigned short cksum;	/* 16-bit Internet checksum    */
    unsigned char payload[PAYLOAD_SIZE];  /* random generated data */
  } item;

int main(int argc, char *argv[]) {
  struct sigaction act;

  act.sa_handler = sig_handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  sigaction (SIGINT, &act, 0);

  item   buffer[BUFFER_SIZE];
  int    in  = 0;
  int    out = 0;
  item next_consumed;

     while (true) {
	while (in == out) {
	   sleep(1); /* do nothing but sleep for 1 second */
	}
    	next_consumed = buffer[out];
    	out = (out + 1) % BUFFER_SIZE;
    	/* consume the item in next_consumed */
    	/* 1. Check for no skipped buffers (item_no is contiguous) */
    	/* 2. Verify the calculated checksum matches what is stored in
	 *            next_consumed */
     }
}
