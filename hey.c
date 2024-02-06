#include <stdio.h>
#include <string.h>

int main() {
    char inputString[100]; // Assuming maximum input string length is 100
    int numColumns, numRows, i, j;

    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = '\0'; // Remove newline character from input

    printf("Enter the number of columns: ");
    scanf("%d", &numColumns);

    // Calculate the number of rows based on string length and number of columns
    numRows = (strlen(inputString) / numColumns)+1;

    char matrix[numRows][numColumns];

    // Populate the 2D array
    for (i = 0; i < numRows; ++i) {
        for (j = 0; j < numColumns; ++j) {
            matrix[i][j] = inputString[i * numColumns + j];
        }
    }

    // Read the array from top to bottom
    printf("Array read from top to bottom:\n");
    for (j = 0; j < numRows; ++j) {
        for (i = 0; i < numColumns; ++i) {
            printf("%c", matrix[j][i]);
        }
        printf("\n");
    }

    return 0;
}