#include "functions.c" //containts all the functions from this program

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

 //when compiling this file compile as usual

/**
 * Authors: Daleela Letyaeva
*/

int *SPEED_CONSTANT[4] = {60, 70, 80};

int main (int argc, char **argv){

if(argc != 3){
   printf("Usage: enter input file name and output filename after %s\n", argv[0]);
   exit(1);
}

if(strcmp(argv[1],argv[2])== 0){
   printf("please enter different output file name.");
}
   FILE *inputFile = fopen(argv[1], "r");
   FILE *outputFile = fopen(argv[2],"w");
//read input file
//testPrint(inputFile);


fclose(argv[1]);
fclose(argv[2]);

//don't forget to free your memory for arrays
return 0;
}