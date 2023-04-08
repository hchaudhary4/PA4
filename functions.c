/*includes both the function implementation functions with structs */

#include "definition.h" //containts all the definitions of the functions

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct CarPackage_struct {
   char *cName = (char*)malloc(sizeof(char) * 20);
   double dragCo;
   double dragArea; 
   double powerArr = (double*)malloc(sizeof(double) * 20);
   int *speed[4] = {60, 70, 80};   
} CAR;


