#include <stdio.h>

int summation(int n)
{
    if (n == 1) return 1;
    return(n + summation(n-1));
}

int main()
{
    printf("%d \n", summation(5));
}