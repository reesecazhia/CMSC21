// Recursive implementation of the Summation of n integers problem
#include <stdio.h>

int summation(int n) {
    if (n==1) { return 1;}  //base case
    else {
        return summation(n-1) + n; //recursive case
    }
}

int main() {
    int n;
    printf("Please enter an integer: ");
    scanf("%d", &n);
    printf("The sum of the integers from 1 to %d is %d.\n", n, summation(n) );

    return 0;
}