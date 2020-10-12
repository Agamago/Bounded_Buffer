nclude <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int ip_checksum(unsigned char *data, int nbytes) 
{ 
 unsigned int sum = 0xffff;
 unsigned short word;
 int  i;
 // Handle complete 16-bit blocks
 for (i = 0; i+1<nbytes; i+=2) {
	memcpy(&word, data+i, 2);
	sum += word;
	if (sum > 0xffff) {
		sum -= 0xffff;
	}
 } 
 // Handle any partial block at the end of the data.
 if (nbytes&1) {
	word=0;
	memcpy(&word, data+nbytes-1, 1);			
	sum += word;;			
	if (sum > 0xffff) {			
		sum -= 0xffff;			
	}			
 } 		
 //Return the checksum
 return ~sum;
}
