/*includes both the function implementation functions with structs */

#include "definition.h" //containts all the definitions of the functions

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct Car_stru {
    char carName[100];
    char dragCo[20];
    char dragArea[20];
    char powerArr[20];
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
        char *cname = strtok(BUFFER, ",");
        strcpy(carArray[i]->carName, cname);
        char *cdragCO = strtok(NULL,",");
        strcpy(carArray[i]->dragCo, cdragCO);
        char *dragarea = strtok(NULL,"\n");
        strcpy(carArray[i]->dragArea, dragarea);
        i++;
        }

    fclose(inputFile);
    }

//sorts the old car array into a new array with cars that have positive drag area
int countPositive(Car **carArray, int const SIZE_ARR, int const SIZE_ELE){
       int count = 0;
        for(int i = 0; i < SIZE_ARR; i++){
            if(atoi(carArray[i]->dragArea) != -1){
            count++;
            }
        }
    return count;
    }

void eliminateCars(int count, int const SIZE_ELE, int const SIZE_ARR, Car **carArray, Car **sortedArray){
        int i =0;
        for(int k = 0; k < SIZE_ARR; k++){
            if(atoi(carArray[k]->dragArea) != -1){
                sortedArray[i] = carArray[k];
                i++;
            }
        }
    printf("integer value for sortedArr: %d\n", i);
}

void printToOutputFile(Car **sortedArray, int count, FILE *outputFile){
   fputs("Car Name;   Drag Coefficient;    Drag Area;\n", outputFile);
    for(int i = 0; i < count; i++){
        fprintf(stdout, "%s", sortedArray[i]->carName);
        fprintf(stdout, ", %s\n", sortedArray[i]->dragArea);
        fputs(sortedArray[i]->carName, outputFile);
        fputs(" ,", outputFile);
        fputs(sortedArray[i]->dragCo, outputFile);
        fputs(" ,", outputFile);
        fputs(sortedArray[i]->dragArea, outputFile);
        fputs("\n", outputFile);
    }
}



