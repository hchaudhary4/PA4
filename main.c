#include "functions.c" //containts all the functions from this program

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

 //when compiling this file compile as usual

/**
 * Authors: Daleela Letyaeva
*/


void main (int argc, char **argv){

int const SIZE = 200; //arbitrary size used to read the lines from input file
int const SPEED[4] = {60, 70, 80}; 
char *Buffer = (char*)malloc(sizeof(char) * SIZE); // temp array to hold the informatino read from input file
Car *cBlockArr = (Car*)malloc(sizeof(Car)* SIZE);

//checks for valid file names and inputs
if(argc != 3){
   printf("Usage: enter input file name and output filename after %s\n", argv[0]);
   exit(1);
}

if(strcmp(argv[1],argv[2])== 0){
   printf("please enter different output file name.");
}




   //read inputfile and print the contents into output file
   //currently it's reading the contents of input file and copying them into output file
   printf("writing output file\n");
   int i = 0;
   while(fgets(Buffer, SIZE, inputFile) != NULL){
     // fputs(Buffer, outputFile); FIXME
     cBlockArr[i].cName = strtok(Buffer, ",");
     cBlockArr[i].dragCo = atof(strtok(NULL, ","));
     cBlockArr[i].dragArea = atof(strtok(NULL, ","));
     i++;

   }
    //print
   printf("finished writing output file\n");
   for(int j =0; j < strlen(cBlockArr); j++){
      fprintf(outputFile, "%s, %lf, %lf", cBlockArr[i].cName,cBlockArr[i].dragCo, cBlockArr[i].dragArea);
     }
//read input file
//testPrint(inputFile);

//close files once done
fclose(inputFile);
fclose(outputFile);

//don't forget to free your memory for arrays
return 0;
}