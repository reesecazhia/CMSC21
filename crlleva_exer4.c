#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void transpose(char *plaintext, char *cyphertext,int key)
{
    char **arrayMatrix, **arrayTransposeMatrix;
    int rowSize, i, j, index = 0;

    if (strlen(plaintext)%key != 0)
    {
        rowSize = (strlen(plaintext)/key) + 1;
    }else
    {
        rowSize = (strlen(plaintext)/key);
    }

    arrayMatrix = (char**) malloc(sizeof(char*)*rowSize);
    for(i=0; i<rowSize; i++) 
    {
        arrayMatrix[i] = (char*) malloc(sizeof(char)*key);
    }

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

    //Populate on arrayTransposeMatrix


    for(i=0; i<key; i++) 
    {
        for(j=0; j<rowSize; j++) 
        {
            arrayTransposeMatrix[i][j] = arrayMatrix[j][i];
        }
    }

    //Print transposed text

    
    for(i=0; i<key; i++) 
    {
        for(j=0; j<rowSize; j++) 
        {
            cyphertext[index] = arrayTransposeMatrix[i][j];
            index+=1;
            
        }
    }

    cyphertext[index+1] = '\0';


    for(i=0; i<rowSize; i++)
        free(arrayMatrix[i]);
    free(arrayMatrix);

    for(i=0; i<key; i++)
        free(arrayTransposeMatrix[i]);
    free(arrayTransposeMatrix);

}

int main()
{
    char plaintext[100];
    char cyphertext[100];

    int key;

    printf("Enter a string: ");
    scanf("%s", plaintext);

    printf("Enter the key (number of columns): ");
    scanf("%d", &key);

    
    transpose(plaintext, cyphertext, key);

    printf("Cyphertext: %s \n", cyphertext);
    
    return 0;
}