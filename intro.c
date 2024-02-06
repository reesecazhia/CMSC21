#include <stdio.h> //preprocessor directive, with this i will be able to use the fxns inside the library (like import)
//we need this to be able to use the input and output functions


int main () { //int is the datatype the fxn returns, main is the name of the fxn, inside parenthesis, put parameters, braces marks start and end of function
	
	//variables holds datatype throughout the program, static
	
	char name[20]; //'name' is identifier, data type char, length is 20 characters
	int age;
	float grade;


	printf("Hello, What is your name?"); 
	scanf("%s", name); //"%s" indicates that i am asking for a string input, to be stored in variable "name" 

	printf("How old are you?");
	scanf("%d", &age); //ampersand is the address operator

	printf("What is your expected grade in CMSC 21?");
	scanf("%f", &grade);

	printf("Hi, my name is %s, I am %d years old. \n", name, age);
	//put %s because i want a string to appear there (applies for %d)
	//order of format identifiers must be the order of the variables

	printf("My expected grade in CMSC 21 is %f \n", grade);

	return 0; //because main fxn is expected to return an int value
}