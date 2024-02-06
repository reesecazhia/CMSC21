// #include <stdio.h> //Preprocessor directives
// #define PI 3.14159 //#define is used to define constants, everytime PI is used it will be replaced with 3.14159

// int main() {
//     int choice;
//     float l,w,b,h,r,area;


//     printf("Please choose one: \n");
//     printf("[1] Rectangle \n");
//     printf("[2] Triangle \n");
//     printf("[3] Circle \n");
//     scanf("%d", &choice);

//     if (choice == 1) {
//         printf("Please enter length.");
//         scanf("%f", &l);
//         printf("Please enter width.");
//         scanf("%f", &w);
//         area = l*w;
//         printf("The area of a rectangle with length %f and width %f is %f.\n", l,w, area);

//     }

//     if (choice == 2) {
//         printf("Please enter base.");
//         scanf("%f", &b);
//         printf("Please enter height.");
//         scanf("%f", &h);
//         area = b*h/2;
//         printf("The area of a triangle with base %f and height %f is %f.\n", b,h, area);

//     }

//     if (choice == 3) {
//         printf("Please enter radius.");
//         scanf("%f", &r);
//         area = PI*r*r;
//         printf("The area of a circle with radius %f is %f.\n", r, area);

//     }

//     return 0;
// }


#include <stdio.h> //preprocessor directive
#define PI 3.14159 //used to define constants, everytime PI is used, it gets replaced by 3.14159

int main (){
    float l, w, b, h, r, area; 

    int choice;

    printf("Please choose one \n");
    printf("[1] Rectangle \n");
    printf("[2] Triangle \n");
    printf("[3] Circle \n");
    scanf("%d", &choice);

    if (choice == 1){
        printf("Enter length: ");
        scanf("%f", &l);
        printf("Enter width: ");
        scanf("%f", &w);
        area = l * w;

        printf("The area of your rectangle is %f. \n", area);
    }

    if (choice == 2){
        printf("Enter base: ");
        scanf("%f", &b);
        printf("Enter height: ");
        scanf("%f", &h);
        area = 0.5 * (b*h);

        printf("The area of your triangle is %f. \n", area);

    }

    if (choice == 3) {
        printf("Enter radius: ");
        scanf("%f", &r); 

        area = PI*r*r;
        printf("The area of your circle is %f. \n", area);

    }
    return 0;
}