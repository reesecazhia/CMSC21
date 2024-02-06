#include <stdio.h>
#include <string.h>

int main(){
char name[20], *name2;
char *prompt = "What is your name?";

printf("%s",prompt);
scanf("%s",name);
name2 = name;
strcpy(name2,"hey");
// scanf("%s",name2); //will this work?

printf("Your name is %s %s.\n",name,name2);

return 0;
}