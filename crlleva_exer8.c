//crlleva_exer8.c
//Lleva, Cazhia Reese CMSC 21 UV-4L

/*
A C program that implements a simple transposition cipher.
This program involves moving the letters around in a grid and then prints the resulting cipher as an encrypted text. 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//transpose() is a function that accepts char pointer plaintext and ciphertext as parameters (passed by reference)
//it also accepts integer key (passed by value)
//This function puts the string input in a grid and transpose it to a ciphertext
void transpose(char *plaintext, char *ciphertext,int key)
{
	//local variables
    char **arrayMatrix, **arrayTransposeMatrix;
    int rowSize, i, j, index = 0, k=strlen(plaintext)%key;
    printf("%d\n", k);
    //Set rowsize depending on the length of the string and key
    if (strlen(plaintext)%key != 0)
    {
        rowSize = (strlen(plaintext)/key) + 1;
    }else
    {
        rowSize = (strlen(plaintext)/key);
    }
    printf("%d\n", rowSize);
    //Dynamically create a 2-dimensional array named arrayMatrix
    arrayMatrix = (char**) malloc(sizeof(char*)*rowSize);
    for(i=0; i<rowSize; i++) 
    {
        arrayMatrix[i] = (char*) malloc(sizeof(char)*key);
    }

    //Dynamically create a 2-dimensional array named arrayTransposeMatrix
    arrayTransposeMatrix = (char**) malloc(sizeof(char*)*key);
    for(i=0; i<key; i++) 
    {
        arrayTransposeMatrix[i] = (char*) malloc(sizeof(char)*rowSize);
    }

    //Populate plaintext on arrayMatrix
    for(i=0; i<rowSize; i++) 
    {
        for(j=0; j<key; j++) 
        {
            arrayMatrix[i][j] = plaintext[i * key+j];
        }
    }

    //Populate on arrayTransposeMatrix with characters from the arrayMatrix grid
    for(i=0; i<key; i++) 
    {
        for(j=0; j<rowSize; j++) 
        {
            arrayTransposeMatrix[i][j] = arrayMatrix[j][i];
        }
    }

    //Put the characters inside the arrayTransposeMatrix into single-dimension array ciphertext
    for(i=0; i<key; i++) 
    {
        for(j=0; j<rowSize; j++) 
        {
        	if(arrayTransposeMatrix[i][j] != '\0')
        	{
	            ciphertext[index] = arrayTransposeMatrix[i][j];
	            index+=1;
        	}
            
        }
    }

  

    ciphertext[index+1] = '\0';


    //Deallocations
    for(i=0; i<rowSize; i++)
        free(arrayMatrix[i]);
    free(arrayMatrix);

    for(i=0; i<key; i++)
        free(arrayTransposeMatrix[i]);
    free(arrayTransposeMatrix);

}//end of transpose function

int main()
{
	//local variables
    char plaintext[100];
    char ciphertext[100];
    int key;


    //ask user for string input
    printf("Enter a string: ");
    scanf("%s", plaintext);

    //ask user for key value (number of columns)
    printf("Enter the key (number of columns): ");
    scanf("%d", &key);

    //call transpose function and pass plaintext, ciphertext, and key
    transpose(plaintext, ciphertext, key);


    //print resulting ciphertext
    printf("Ciphertext: %s \n", ciphertext);
    
    return 0;
}//end of main function