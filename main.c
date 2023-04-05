#include "functions.c" //containts all the functions from this program

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

 //when compiling this file compile as usual

/**
 * Authors: Daleela Letyaeva
*/

int main (int argc, char **argv){

if(argc != 2){
   printf("Usage: enter string after %s\n", argv[0]);
   exit(1);
}

   char *inputFile = argv[1]; // cannot enter spaces for the entry

//read input file
testPrint(inputFile);



//don't forget to free your memory for arrays
return 0;
}