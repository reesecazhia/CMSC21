#include <stdio.h>

int summation(int i, int n)
{
    if (n==i) return (n);
    return (i + summation(i+1, n));
}

int main()
{
    printf("%d \n", summation(1,5));
}