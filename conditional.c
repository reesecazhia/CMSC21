// if condition syntax: 

// if (expression){
	//code block to be executed if expression is non-zero
	//no boolean values in C, false is zero value
//}

#include <stdio.h> //preprocessor directive

int main (){
	//int a = 0, b=1; //initialize this a int variable as 0

	//this f statement works as:
	//if (a) printf("hello \n");  //if this evaluates as non-zero, execute lines inside
		//the curly braces are not necessary if isag line lan yung i-eexecute na codeblock

	//else if (b)//this makes hi as part of the else statement

	// in this example, hi would notbe printed if a is zero
	//printf("hi \n"); else 
	
	//if hindi pumasok sa hi, di na mapeperform ang bye
	// if non-zero ang b, di na rin papasok dito
	//evaluated all the time not belonging to if statement
	//printf("bye! \n");
	float BMI;

	printf("Enter here: ");
	scanf("%f", &BMI);
	

		if (BMI < 18.5)
			printf("BMI Category: Underweight \n");
		
		else if (BMI >= 18.5 && BMI <=24.9) 
			printf("BMI Category: Normal weight \n");
		
		else if (BMI>24.9 && BMI <=29.9)
			printf("BMI Category: Overweight \n");
		
		else if (BMI > 29.9)
			printf("BMI Category: Obesity \n");
		
	return 0;
}