//crlleva_ex2.c
//Cazhia Reese Lleva 14 Sep 2023
//CMSC 21 UV-4L

/*
Code Description:
This program calculates the BMI of the user.
The user has two choices: to calculate using the standard system or the metric system. 
Once, the user makes their choice, the necessary input data are requested.  
This program outputs the calculated BMI and its respective category. 
*/

#include <stdio.h> //preprocessor directive

int main () //this is the main function
{
	//variable declarations
	float kg, cm, ft, in, lbs, BMI, TotalHeight; //variables of type 'float' are needed in the BMI calculation
	int choice; //the user will input an integer choice based on the menu
	char ans = 'n'; //initialize the 'ans' variable to 'n'

	do
	{
		//These will be printed as long as the while condition holds True
		printf("\n[MENU] Please choose one. \n");
	    printf("[1] Measure in metric \n");
	    printf("[2] Measure in standard \n");
	    printf("[3] Exit \n");
	    printf("Enter your choice here: " );
	    scanf("%d", &choice); //Gets the integer input from the user
	    switch (choice) //This evaluates the 'choice' variable
	    {
	    	case 1: //If choice == 1, the user chose to measure using the metric system
	    		//these lines of code will be executed
	    		printf("\nYou have chosen to measure in metric! \n");
		    	printf("Enter weight in kilograms: ");
		    	scanf("%f", &kg);

		    	printf("Enter height in centimeters: ");
		    	scanf("%f", &cm);


		    	cm = cm/100; //convert the centimeter input to meters
		    	//BMI formula using the metric system
		    	BMI = kg/(cm*cm);

		    	//Show the user the calculated BMI
		    	printf("Your BMI is: %0.2f \n", BMI); //show only 2 decimal places

		    	//These evaluates the calculated BMI, whether it belongs to the categories: Underweight, Normal, Overweight or Obese
		    	if (BMI < 18.5) printf("BMI Category: Underweight \n");
		    	else if (BMI >= 18.5 && BMI <= 24.9) printf("BMI Category: Normal weight \n"); //upper limit is 24.9 (any value larger is already included in the next category)
		    	else if (BMI > 24.9 && BMI <=29.9) printf("BMI Category: Overweight \n"); //upper limit is 29.9 (any value larger is already included in the next category)
		    	else if (BMI > 29.9) printf("BMI Category: Obesity \n");

		    	break;

		    case 2: //If choice == 2, the user chose to measure using the standard system
		    	//these lines of code will be executed
		    	printf("\nYou have chosen to measure in standard! \n");
		    	printf("Enter weight in pounds: ");
		    	scanf("%f", &lbs);

		    	printf("Enter height in feet: ");
		    	scanf("%f", &ft);

		    	printf("Enter height in inches: ");
		    	scanf("%f", &in);

		    	//Calculate the total height from feet and inches
		    	TotalHeight = (ft*12) + in;
		    	//BMI formula using the standard system
		    	BMI = (lbs/(TotalHeight*TotalHeight))*703;

		    	//Show the user the calculated BMI
		    	printf("Your BMI is: %0.2f \n", BMI);

		    	//These evaluates the calculated BMI, whether it belongs to the categories: Underweight, Normal, Overweight or Obese
		    	if (BMI < 18.5) printf("BMI Category: Underweight \n");
		    	else if (BMI >= 18.5 && BMI <= 24.9) printf("BMI Category: Normal weight \n");
		    	else if (BMI > 24.9 && BMI <= 29.9) printf("BMI Category: Overweight \n");
		    	else if (BMI > 29.9) printf("BMI Category: Obesity \n");
		    	
		    	break;

		    case 3: //if choice == 3, the user has chosen to exit the program
		    	//ask the user if they are sure
		    	printf("Are you sure? (y/n): ");
		    	scanf(" %c", &ans); //changes "ans" variable value
		    	break;

		    case 4: 
		    	printf("Added for testing");

		    default: //If the user input an integer not part of the choices, this will be shown
		    	printf("\nInvalid choice. Try again. \n");
		}

    } while (ans != 'y'); //The blocks of code are executed and the user will continue to see the options until they choose 3 and change the value of the "ans" variable to 'y'

    printf("Bye!");

    return 0;
} //end of main
