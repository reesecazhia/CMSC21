//crlleva_exer4.c
//Cazhia Reese Lleva UV-4L

//This program returns the population of n after x years with an annual growth rate of y.


#include <stdio.h>


float population(float i, float n, float y, float x)
{
    if (i == x) return n;
    return ((population(i+1, n, y, x))+ population(i+1, n, y, x)*y);
} //end of population function

int main()
{
    float n, y, x, decimal_y;

    printf("Population (n): \n");
    scanf("%f", &n);
    printf("Growth Rate (y): \n");
    scanf("%f", &y);
    decimal_y = y/100;
    printf("Years (x): \n");
    scanf("%f", &x);

    
    printf("Result: \n");
    printf("After %f years at %f percent growth rate, the population will be %f .\n", x, y, population(1, n,decimal_y,x));

} //end of main