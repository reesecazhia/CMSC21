#include <stdio.h>

int summation(int n)
{
    int i, s = 0;
    for (i = 0; i<n; i++)
        s += i+1;
    return (s);
}

int main()
{
    printf("%d \n", summation(5));
}