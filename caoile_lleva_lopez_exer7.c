//caoile_lleva_lopez_exer7.c
//Ralph Philip Caoile, Cazhia Reese Lleva, John A-Jaye Lopez 
//CMSC 21 UV-4L

/*
A C program that checks whether the given word is a palindrome or not, that is it checks if a user inputs a word
that can be read the same way forward or backward. The program has two functions: isPalindrome() and the main() function. 
Before exiting the program, the user will see the words they entered that were evaluated as palindromes.
This program implements C's one-dimensional and multidimensional arrays, as well as Strings.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

//isPalindrome() function accepts a char pointer as a formal parameter. 
//This function checks whether a word is a palindrome or not and returns an integer 1(True) or 0(False).

int isPalindrome(char *s)
{
    int i, n;
    n = strlen(s)/2;
    
    for(i=0; i<n; i++) 
    {
        if (s[strlen(s)-(i+1)] != s[i])
        {
            return 0;
        }
    }
    return 1;
    
}//end of isPalindrome()


//This function is the starting point of the program.
//It handles showing the user whether the word they entered is a palindrome or not. 
//It also shows the entered palindrome once the user decides to exit the program.
int main()
{
    //variable declarations and initializations
    char exit[] = "EXIT";
    char store[10][20];  
    char word[20];
    int exitFlag=1,boolFlag, i=0, j;
    
    //an infinite loop that runs unless user enters "EXIT"
    while(exitFlag!=0)
    {   

        printf("Enter your word to check if it is a palindrome: ");
        scanf("%s", word);
        exitFlag=strcmp(exit,word);
        
        if(exitFlag!=0){
            //invoke isPalindrome() function
            boolFlag = isPalindrome(word);

            //if word is a palindrome, store it inside store[][] array
            if(boolFlag!=0){
                printf("%s is a palindrome!\n\n",word);
                strcpy(store[i],word);              
                i+=1;    

            }
            else
            {
                printf("%s is not a palindrome!\n\n",word);
            }
        }
    
    } //end of while loop

    
    //If the user entered a palindrome, display these words to the user. 
    if(i!=0)
    {
        printf("\nYou have chosen to exit the program. \nHere are the words you entered that are palindromes:\n");
        for(j=0; j<i; j++) {
            printf("[%d] %s \n", j+1, store[j]);
        }
    }
    
    //program exits
    printf("\nBye!\n");
           
}//end of main


