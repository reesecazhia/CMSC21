#include<stdio.h>
#include <string.h>


int main(){
char name[20], *name2 = "name";
char prompt[] = "What is your name?";

printf("%s",prompt);
scanf("%s",name);
// strcpy(name2, name);
printf("%d\n",strlen(prompt)); //will this work?
printf("%c\n",prompt[strlen(prompt)]);
// printf("Your name is %s.\n",name2);

return 0;
}
