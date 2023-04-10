#include "functions.c" //containts all the functions from this program

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


/**
 * Authors: Daleela Letyaeva
*/
typedef struct Car_stru {
    char carName[100];
    float dragCo;
    float dragArea;
    float powerArr;
} Car;


//function to process information by car
void subdivideCars(char *argv[1], Car **carArray){

}



void main (int argc, char **argv){
    int SIZE = 300;
    Car **carArray = (Car**) malloc (sizeof(Car*)*SIZE); // allocated memory for the general array
    for(int i =0; i < SIZE; i++){
        Car *carNum = (Car*) malloc (sizeof(Car) * SIZE); // allocated memory for each element in the array
    }
    

    // read input file
   FILE *inputFile = fopen(argv[1], "r");
   
   if(inputFile == NULL){
   printf("error reading file");
   exit(1);
   }

    //process file
    // function that that creates a variable for each car
    //and stores those variables in a array

    char *Buffer = (char*)malloc(sizeof(char) * SIZE);
    
    
    for(int i = 0; i < SIZE; i++ ){
        Car *carNum = (carNum*)malloc(sizeof(carNum)*SIZE);
    }




    //print output file
    FILE *outputFile = fopen(argv[2],"w");


fclose(inputFile);
free(Buffer);
return;
}