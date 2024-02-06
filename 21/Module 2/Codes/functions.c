//Implementation of the Areas of Geometric Figures using functions
#include <stdio.h>
#define pi 3.14159

//function prototypes
float rectangle(float, float);
float triangle(float, float);
float circle(float);

int main() {
    int choice;
    float floatarea,b,h,r,l,w;


    printf("Please choose one: \n");
    printf("[1] Rectangle \n");
    printf("[2] Triangle \n");
    printf("[3] Circle \n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
        printf("Please enter length.");
        scanf("%f", &l);
        printf("Please enter width.");
        scanf("%f", &w);
        printf("The area of a rectangle with length %f and width %f is %f.\n", l,w, rectangle(l,w));
        break;
        case 2:
        printf("Please enter base: ");
        scanf("%f", &b);
        printf("Please enter height: ");
        scanf("%f", &h);
        printf("The area of a triangle with base %f and height %f is %f.\n", b,h, triangle(b,h));
        break;
        case 3:
        printf("Please enter radius: ");
        scanf("%f", &r);
        printf("The area of a circle with radius %f %f.\n", r, circle(r));
        break;

    }


    return 0;
}

float rectangle(float l, float w) {
    float area;
    area = l*w;
    return area;
}

float triangle(float b, float h) {
    float area;
    area = b*h/2;
    return area;
}

float circle(float r)
{
    float area;
    area = pi*r*r;
    return area;
}
