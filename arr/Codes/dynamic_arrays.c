//Entering grades using dynamic arrays
#include <stdio.h>
#include <stdlib.h> // we need this for malloc

int main() {
    float *grades; // pointer declaration
    int i, size=3;

    grades = (float *) malloc (sizeof(float)*size);

    for(i=0; i<size; i++) { //loop for accessing each element in the array
        printf("Eneter grade in the subject %d: ", i+1);
        scanf("%f", &grades[i]); //getting the address of the ith element
    }

    for (i=0; i<size; i++) {
        printf("Your grade in subject %d is %f.\n", i+1, grades[i]);
    }

    free(grades); //free memory allocated for  grades
    return 0;
}