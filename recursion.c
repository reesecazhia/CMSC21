#include <stdio.h>


int factorial (int n);
int main()
{
	int varHolder;
	int n;
	printf("Find factorial of: ");
	scanf("%d", &n);
	varHolder = factorial(n);
	printf("%d \n", varHolder);
	return 0;
}

int factorial(int n)
	{
		if (n == 0){
			return 0;
		}
		else if (n == 1){
			return 1;
		}

		return (n * factorial(n-1));
	}