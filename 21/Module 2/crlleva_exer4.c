//crlleva_exer4.c
//Cazhia Reese Lleva UV-4L

//This program returns the population of n after x years with an annual growth rate of y.


#include <stdio.h>


float population(float n, float y, float x)
{
    if (x == 0) return n;
    return ((population(n, y, x-1))+ population(n, y, x-1)*y);
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
    printf("After %f years at %f percent growth rate, the population will be %f .\n", x, y, population(n,decimal_y,x));

} //end of main