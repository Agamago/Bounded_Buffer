/*
 * Joey Sheridan
 * csheridan@chapman.edu
 * Operating Systems Assignment #3
 * Bounded_Buffer
 * producer.c
 *
 */


#define MMAP_SIZE   4096
#define BUFFER SIZE 100
#define PAYLOAD_SIZE 34

  typedef struct {
   	int    item_no;		/* number of the item produced */
   	unsigned short cksum;   /* 16-bit Internet checksum    */
	unsigned char payload[PAYLOAD_SIZE];  /* random generated data */} item;
	item   buffer[BUFFER_SIZE];
	int    in  = 0;
	int    out = 0;
	item next_produced;
       	while (true) {
		/* produce an item in next_produced */
		/* 1. Increment the buffer count (item_no)  */
		/* 2. Calculate the 16-bit checksum (cksum) */
		/* 3. Generate the payload data             */
		/*    next_produced.payload[n] = (unsigned char) rand() % 256 */
	    
		while (((in + 1) % BUFFER SIZE) == out)
	       		sleep(1); /* do nothing but sleep for 1 second */
	    	buffer[in] = next produced; /* store next_produced into shared
	   				       buffer */                      
	     	in = (in + 1) % BUFFER SIZE;
	}
}
