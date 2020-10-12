1. Joey Sheridan
   002290839
   csheridan@chapman.edu
   CPSC 353-01
   Bounded_Buffer

2. consumer.c , producer.c , ip_checksum.c, a.out, README.md

3. Does not run properly. The program compiles and runs a limited loop displaying the checksum value of 
	the argument passed while pushing it to shared memory.
	Upong issuing a force quite command (ctrl c), the signal catcher gracefully exits the program and cleans the
	memory.
	Memory is added to the shared memory each iteration of the while loop, but the consumer is unfinished and does
	not yet do anything with the shared memory

4.	No Sources for this assignment except Canvas

5. In order to run this program, build by typing g++ producer.c and run by typing ./a.out ______ 
	Fill the blank with the string you would like converted to checksum form
	Use ctrl + c to exit the program
