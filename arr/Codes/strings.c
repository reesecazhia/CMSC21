//Static and Dynamic Strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char static_str[50];
    char *dynamic_str;

    printf("Enter string: ");
    scanf("%s", static_str);

    printf("You have entered the string %s\n", static_str);

    dynamic_str = (char*) malloc(sizeof(char)*100);
    printf("Enter another string: ");
    scanf("%s", dynamic_str);

    printf("The other you have entered is %s\n", dynamic_str);
    
    printf("Using strcat on both strings = %s\n", strcat(static_str,dynamic_str)); 
    printf("The length of static_str is %d\n", (int)strlen(static_str)); 

    //try out the other string functions
    free(dynamic_str);
    return 0;

}
