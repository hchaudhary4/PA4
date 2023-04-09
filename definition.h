/*contains definitions of both regular functions and structs
*/
#ifndef DEFINITION_H
#define DEFINITION_H
//CONTENT

void userInput(char *userInput);


/*
*this struct stores the data associated with the car
*/
struct Car{
   char cName[100];
   double dragCo;
   double dragArea; 
   double powerArr[4];
   int speed[4];   
} block;

#endif