//crlleva_exer3.c
//Cazhia Reese Lleva 14 Sep 2023
//CMSC 21 UV-4L

/*
Code Description
This program calculates the BMI of the user. The user has two choices: to calculate using the standard system or the metric system. 
Once, the user makes their choice, the necessary input data are requested. This program outputs the calculated BMI and its respective category. 
*/

#include <stdio.h> //preprocessor directive

//function prototypes
void showBMI(float bmi);
float getBMIMetric();
float getBMIStandard();

int main()
{
    int choice; //the user will input an integer choice based on the menu
    char ans = 'n'; //initialize the 'ans' variable to 'n'

    do{
        printf("\n[MENU] Please choose one. \n");
        printf("[1] Measure in metric \n");
        printf("[2] Measure in standard \n");
        printf("[3] Exit \n");
        printf("Enter your choice here: " );
        scanf("%d", &choice); //Gets the integer input from the user
        printf("\n");
        switch (choice) //This evaluates the 'choice' variable
        {
            case 1:
                showBMI(getBMIMetric());
                break;
            case 2:
                showBMI(getBMIStandard());
                break;
            case 3: 

                printf("Are you sure? (y/n): ");
                scanf(" %c", &ans); //changes "ans" variable value
            break;
            default: //If the user input an integer not part of the choices, this will be shown
            printf("\nInvalid choice. Try again. \n");
        }
    }while(ans != 'y');

    printf("Bye!");

    return 0;
} //end of main

float getBMIMetric()
{
    float kg, cm, bmi;
    printf("Enter weight in kilograms: ");
    scanf("%f", &kg);

    printf("Enter height in centimeters: ");
    scanf("%f", &cm);

    cm = cm/100; //convert the centimeter input to meters
    //BMI formula using the metric system
    bmi = kg/(cm*cm);
    return (bmi);
} //end getBMIMetric

float getBMIStandard()
{
    float ft, in, lbs, TotalHeight, bmi;
    
    printf("Enter weight in pounds: ");
    scanf("%f", &lbs);

    printf("Enter height in feet: ");
    scanf("%f", &ft);

    printf("Enter height in inches: ");
    scanf("%f", &in);

    //Calculate the total height from feet and inches
    TotalHeight = (ft*12) + in;
    //BMI formula using the standard system
    bmi = (lbs/(TotalHeight*TotalHeight))*703;
    return (bmi);
} //end getBMIStandard

void showBMI(float bmi)
{
    printf("Your BMI is: %0.2f \n", bmi);

    if (bmi < 18.5) printf("BMI Category: Underweight \n");
    else if (bmi < 24.9) printf("BMI Category: Normal weight \n"); 

    else if (bmi < 29.9) printf("BMI Category: Overweight \n"); 
    
    else printf("BMI Category: Obesity \n");
} //end showBMI
