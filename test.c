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
    double dragCo;
    double dragArea;
    double powerArr[4];
} Car;


//function to process information by car
void subdivideCarsFromInput(FILE *inputFile, Car *carNum, int const SIZE_ELE, int const SIZE_ARR, char *BUFFER){
    int i = 0;
    FILE *in = inputFile;
    while(fgets(BUFFER, SIZE_ARR, in) != NULL){
        //BUFFER[strlen(BUFFER) - 1] = "\0";
        //
        char *cname = strtok(BUFFER, ",");
        strcpy(carNum[i].carName, cname);
        char *cdragCO = strtok(NULL,",");
        carNum[i].dragCo = atof(cdragCO);
        char *dragarea = strtok(NULL,",");
        carNum[i].dragArea = atof(dragarea);
        }

    }



void main (int argc, char **argv){
    
    //read input file
    FILE *inputFile = fopen(argv[1], "r");

    //check that user enters in/out file name
    if(argc != 3){
    printf("Usage: enter input file name and output filename after %s\n", argv[0]);
    exit(1);
    }

    //try to avoid user from confusing the 2 files
    if(strcmp(argv[1],argv[2])== 0){
    printf("please enter different output file name.");
    }

   //check for file not to be empty
    if(inputFile == NULL){
     printf("error reading file");
     exit(1);
    }

    int const SIZE_ARR = 300;
    int const SIZE_ELE = 100;

    char *BUFFER= (char*)malloc(sizeof(char) * SIZE_ELE);

    Car **carArray = (Car**) malloc (sizeof(Car*) * SIZE_ARR); // allocated memory for the general array
    Car *carNum;
    for(int i =0; i < SIZE_ARR; i++){
        carNum = (Car*) malloc (sizeof(Car) * SIZE_ELE); // allocated memory for each element in the general array
    }


    
    //open output file
    FILE *outputFile = fopen(argv[2],"w");
    
    //process file
    //read input file line by line
    //and catagorize the information
    subdivideCarsFromInput(inputFile, carNum, SIZE_ELE, SIZE_ARR, BUFFER);
    
    for(int k = 0; k < SIZE_ARR; k++){
    fprintf(inputFile,"%s %.2lf %.2lf", carNum[k].carName,carNum[k].dragCo, carNum[k].dragArea);
    }
        
    //close the input file
    fclose(inputFile);

return;
}