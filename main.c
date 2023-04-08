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

int const SIZE = 200; //arbitrary size used to read the lines from input file
int const SPEED[4] = {60, 70, 80}; 
char *Buffer = (char*)malloc(sizeof(char) * SIZE); // temp array to hold the informatino read from input file

//checks for valid file names and input
if(argc != 3){
   printf("Usage: enter input file name and output filename after %s\n", argv[0]);
   exit(1);
}

if(strcmp(argv[1],argv[2])== 0){
   printf("please enter different output file name.");
}


   FILE *inputFile = fopen(argv[1], "r");
   
   if(inputFile == NULL){
   printf("error reading file");
   exit(1);
   }

   FILE *outputFile = fopen(argv[2],"w");

   //read inputfile and print the contents into output file
   while(fgets(Buffer, SIZE, inputFile)){
      fprintf(stdout, "%s", Buffer);
   }
   
//read input file
//testPrint(inputFile);

//close files once done
fclose(inputFile);
fclose(outputFile);

//don't forget to free your memory for arrays
return 0;
}