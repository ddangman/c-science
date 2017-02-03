/** bit fields are used to save memory
 https://www.tutorialspoint.com/cprogramming/c_bit_fields.htm */

 // int is usually 4 bytes in modern compilers, 2 for old technologies
 // float uses 4 bytes and precise to 6 decimals
 // double uses 8 bytes and precision to 15 decimals

#include <stdio.h>
#include <string.h>

/* define simple structure */
// no bit so compiler assigns maximum bytes of two int == 8 bytes
struct {
   unsigned int widthValidated;
   unsigned int heightValidated;
} status1;

/* define a structure with bit fields using colon : bit value*/
// assigning more than 32 bits to int causes compilation error
struct {
   unsigned int widthValidated : 32;
   unsigned int heightValidated : 32;
} status2;

// if 0 is assigned, compiler error
struct {
   unsigned int widthValidated : 1;
   unsigned int heightValidated : 1;
} status3;

// maximum value for 4 bytes is 32 bits. 8 bits == 1 byte, 4 bytes == 32 bits
struct {
   unsigned int widthValidated : 16;
   unsigned int heightValidated : 16;
} status4;

// 33 bits requires 8 bytes since compiler will allocate maximum int 4 bytes to each
// and the unused bits will be there as buffer
struct {
   unsigned int widthValidated : 16;
   unsigned int heightValidated : 17;
} status5;

struct {
   unsigned int widthValidated : 15;
   unsigned int heightValidated : 17;
} status6;

struct {
   unsigned int widthValidated : 2;
   unsigned int heightValidated : 30;
} status7;

int main( ) {
   // sizeof returns the size of the type in bytes
   printf( "Memory size occupied by status1 : %d\n", sizeof(status1)); //8
   printf( "Memory size occupied by status2 : %d\n", sizeof(status2)); //8
   printf( "Memory size occupied by status3 : %d\n", sizeof(status3)); //4
   printf( "Memory size occupied by status4 : %d\n", sizeof(status4)); //4
   printf( "Memory size occupied by status5 : %d\n", sizeof(status5)); //8
   printf( "Memory size occupied by status6 : %d\n", sizeof(status6)); //4
   printf( "Memory size occupied by status7 : %d\n", sizeof(status7)); //4

   return 0;
}
