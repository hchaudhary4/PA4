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

//pre-reads the input file to figure out how many rows it has ==> how big general array needs to be
int getFileRows(char *BUFFER, FILE *inputFile){
int i = 0;
while(fgets(BUFFER, 200, inputFile) != NULL){
    i++;
}
fclose(inputFile);
return i;
}
//function to process information by car
void subdivideCarsFromInput(char const *inFILE, Car **carArray, int const SIZE_ELE, int const SIZE_ARR, char *BUFFER){
    FILE *inputFile = fopen(inFILE, "r");

    if(inputFile == NULL){
     printf("error reading file\n");
     exit(1);
    }
    int i = 0;
    while(fgets(BUFFER, SIZE_ELE, inputFile) != NULL){
       // BUFFER[strlen(BUFFER)-1] = '\0';
        char *cname = strtok(BUFFER, ",");
        strcpy(carArray[i]->carName, cname);
        char *cdragCO = strtok(NULL,",");
        carArray[i]->dragCo = atof(cdragCO);
        char *dragarea = strtok(NULL,"\n");
        carArray[i]->dragArea = atof(dragarea);
        i++;
        }

    fclose(inputFile);
    }



void main (int argc, char **argv){

    //check that user enters in/out file name
    if(argc != 2){ //FIXME LATER
    printf("Usage: enter input file name and output filename after %s\n", argv[0]);
    exit(1);
    }

    //try to avoid user from confusing the 2 files
    /*
    if(strcmp(argv[1],argv[2])== 0){
    printf("please enter different output file name.");
    }
    */
    
    //read input file
    char const *inFILE = argv[1];
    FILE *inputFile = fopen(inFILE, "r");
    

   //check for file not to be empty
    if(inputFile == NULL){
     printf("error reading file");
     exit(1);
    }

    
    int const SIZE_ELE = 100;
    char *BUFFER= (char*)malloc(sizeof(char) * SIZE_ELE);

    int const SIZE_ARR = getFileRows(BUFFER, inputFile);
    printf("# of file rows = %d\n", SIZE_ARR);
    
    //close the input file
    

    Car **carArray = (Car**) malloc (sizeof(Car*) * SIZE_ARR); // allocated memory for the general array
    for(int i =0; i < SIZE_ARR; i++){
        carArray[i] = (Car*) malloc (sizeof(Car) * SIZE_ELE); // allocated memory for each element in the general array
    }


    
    //open output file
  //FILE *outputFile = fopen(argv[2],"w");
    
    //process file
    //read input file line by line
    //and catagorize the information
    subdivideCarsFromInput(inFILE, carArray, SIZE_ELE, SIZE_ARR, BUFFER);


    for(int k = 0; k < SIZE_ARR; k++){
    fprintf(stdout,"row[%d]: %s %.2lf %.2lf\n", k, carArray[k]->carName,carArray[k]->dragCo,carArray[k]->dragArea);
    }
        


free(BUFFER);
free(carArray);

return;
}
