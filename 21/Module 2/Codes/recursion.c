#include <stdio.h>

int fib (int n) {
    if (n == 0) return 0; else // base case (n==0)
    if (n == 1) return 1; else // base case (n==1)
    
     return fib(n-1) + fib(n-2); //recursive case
    
    
}

int main() {
    int n;
    printf("Please enter an integer: ");
    scanf("%d", &n);
    printf("Fib of %d is %d\n", n,fib(n));
    return 0;
}