#include <stdio.h>

void largeTwo(int num, int *largest, int *larger)
{
	if(num>*largest)
	{
		*larger = *largest;
		*largest = num;
	}else if(num>*larger)
	{
		*larger = num;
	}
}

int gcf(int a, int b)
{
	int remainder;
	while(b!=0){
		remainder = a%b;
		a = b;
		b=remainder;
	}
	return a;
}

int lcm(int a, int b)
{
	int lcm, product;
	product = a*b;
	lcm = product/gcf(a,b);
	return lcm;
}

int digit(int n)
{
	if (n==0){
		return 0;
	}

	return 1+digit(n/10);
}

void counter(int n, int *odd, int *even)
{
	int current;
	while(n!=0)
	{
		current = n%10;

		if(current%2 == 0){
			*even+=1;
		}else{
			*odd+=1;
		}
		n=n/10;
	}
}

void draw(int n){
	if(n==0){
		printf("\n");
	}else if(n%2 == 0){
		printf("-");
		draw(n-1);
	}else{
		printf("*");
		draw(n-1);
	}
}

void draw(int n)
{
	int i;
	for(i=2; i<=n+1; i++)
	{
		if(i%2 == 0){
			printf("-");
		}else{
			printf("*");
		}
	}
	printf("\n");
}

int main(){
	// int n, larger = 0, largest = 0, i, num;

	// printf("How many? \n");
	// scanf("%d", &n);

	// for (i=0; i<n;i++)
	// {
	// 	printf("Enter an int: \n");
	// 	scanf("%d", &num);
	// 	largeTwo(num, &largest, &larger);
	// }

	// printf("The two largest numbers: %d, %d.\n",larger,largest);





	// int a,b,c,lcmab, lcmabc;

	// printf("Enter a: ");
	// scanf("%d",&a);

	// printf("Enter b: ");
	// scanf("%d",&b);

	// printf("Enter c: ");
	// scanf("%d",&c);

	// lcmab=lcm(a,b);
	// lcmabc=lcm(lcmab,c);

	// printf("LCM: %d",lcmabc);




	// int n;
	// int even=0, odd=0;
	// printf("Enter: \n");
	// scanf("%d",&n);
	// counter(n,&odd,&even);
	// printf("Odd count: %d \nEven count: %d \n",odd, even);

	// int n=2,loopcount=0;

	// while(loopcount<30){
	// 	int prime=1,prime2=1;
	// 	int i,j;
	// 	for(i=2;i<n;i++)
	// 	{
	// 		if(n%i==0)
	// 		{
	// 			prime =0;
	// 			break;
	// 		}
	// 	}

	// 	for(j=2;j<n+2;j++){
	// 		if((n+2)%j == 0)
	// 		{
	// 			prime2=0;
	// 			break;
	// 		}
	// 	}
	// 	if(prime!=0&&prime2!=0)
	// 	{
	// 		printf("%d, %d \n",n,n+2);
	// 		loopcount+=1;
	// 	}

	// 	n+=1;
	// 	}

		draw(10);

	}



