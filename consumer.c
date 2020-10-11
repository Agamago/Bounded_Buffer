#define NMAP_SIZE   4096
#define BUFFER SIZE 100
#define PAYLOAD_SIZE 34

  typedef struct {
     int    item_no;		/* number of the item produced */
     unsigned short cksum;	/* 16-bit Internet checksum    */
     unsigned char payload[PAYLOAD_SIZE];  /* random generated data */} item;
     item   buffer[BUFFER_SIZE];
     int    in  = 0;
     int    out = 0;

     while (true) {
	while (in == out)
	   sleep(1); /* do nothing but sleep for 1 second */
    	next_consumed = buffer[out];
    	out = (out + 1) % BUFFER SIZE;
    	/* consume the item in next_consumed */
    	/* 1. Check for no skipped buffers (item_no is contiguous) */
    	/* 2. Verify the calculated checksum matches what is stored in
	 *            next_consumed */
     }
}
