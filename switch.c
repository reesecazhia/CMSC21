//switch statements allows checking whether a given value is equal to the listed value inside the statement

//switch (expression){ //if expression
	//case constant_expression: //is equal to constant_expression
		//code_block;
		//break;
// }



#include <stdio.h> //preprocessor directive
#define PI 3.14159

int main (){
    float l, w, b, h, r, area; 

    int choice;

    do {
    printf("Please choose one \n");
    printf("[1] Rectangle \n");
    printf("[2] Triangle \n");
    printf("[3] Circle \n");
    scanf("%d", &choice);

    switch (choice){ //we want to test choice
    	case 1: //if it is equal to 1, perform area computation for rectangle
    		printf("Enter length: ");
    		scanf("%f", &l);
    		printf("Enter width: ");
    		scanf("%f", &w);
    		area = l * w;

    		printf("The area of your rectangle is %f. \n", area);
    		break;
    	case 2:
    		printf("Enter base: ");
    		scanf("%f", &b);
    		printf("Enter height: ");
    		scanf("%f", &h);
    		area = 0.5 * (b*h);

    		printf("The area of your triangle is %f. \n", area);
    		break;
    	case 3:
    		printf("Enter radius: ");
    		scanf("%f", &r); 

    		area = PI*r*r;
    		printf("The area of your circle is %f. \n", area);
    		break;

        case 0:
            printf("Bye!");
            break;
    	default:
    		printf("Error");
    }

} while (choice != 0);
    return 0; 
}

//a default is used if user entered something not in the choices, the default statements will be executed