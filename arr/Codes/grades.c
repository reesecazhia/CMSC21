#include <stdio.h>

int main() {
    float grades[3]; //array declaration
    int i, size = 3;

    for(i=0; i < size; i+=1) { //loop for accessing each element in the array
        printf("Enter grade in subject %d: ", i+1);
        scanf("%f", &grades[i]); //getting the address of the ith element
    }

    for(i=0; i < size; i+=1) {
        printf("Your grade in subject %d is %f: \n", i+1, grades[i]);
        
    }
}