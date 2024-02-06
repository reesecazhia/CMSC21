#include <stdio.h>



int main(){
int i, n, j;
printf("Size: \n");

scanf("%d", &n);

for (i=0; i<2*n; i++)
{
	
	for (j=0; j <2*n; j++)
	{
		if ( j==n-1 || i == n-1 || j+i==(2*n-1) || j==i )
		{
			printf("*");
		}else
		{
			printf(" ");
		}
	}
	// printf("here\n");
	printf("\n");
}

for (i=0; i<=2*n; i++)
{
	
	for (j=0; j <=2*n; j++)
	{
		if ( j==n || i == n || j+i==(2*n) || j==i )
		{
			printf("*");
		}else
		{
			printf(" ");
		}
	}
	// printf("here\n");
	printf("\n");
}

	for (i=0; i<n; i++)
	{
		for (j=0; j< 2*n-1-i; j++)
		{
			if(i+j < n-1){
				printf(" ");
			}else{
				printf("%d",j);
			}
		}
		printf("\n");
	}
	// printf("here\n");
	for (i=0; i<n; i++)
	{
		for (j=0; j< 2*n+1; j++)
		{
			if(j<= i){
				printf(" *");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}

	for (i=0; i<2*n-1; i++)
	{
		for (j=0; j<n; j++)
		{
			if(i<=j|| i+j >=(2*n)-2){
				printf("*");
			}else{
				printf(" ");
			}
		}
		
		printf("\n");
	}

	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if(i-j<1){
				printf("* ");
			}else{
				printf(" ");
			}
		}
		
		printf("\n");
	}

	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if(j+i >= n-1){
				printf("* ");
			}else{
				printf(" ");
			}
		}
		
		printf("\n");
	}
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if(j+i >= n-1){
				printf("* ");
			}else{
				printf(" ");
			}
		}
		
		printf("\n");
	}

	for (i=0; i<n; i++)
	{
		
		for (j=0; j-i<= n-1; j++)
		{
			if(j+i < n-1){
				printf(" ");
			}else{
				printf("*");
			}
		}

		printf("\n");
	}

	for (i=0; i<(2*n); i++)
	{
		int row;
		if (i<n-1)
		{
			row = 2*n-i;
		}else if (i==n-1){
			row =2*n;
		}else{
			row=i+1;
		}

		for (j=0; j< row; j++)
		{
			if(j==(n-1) || i == (n-1) || j==(2*n-1-i) || j==i ){
				printf("*");
			}else{
				printf("_");
			}
		}
		
		printf("\n");
	}

	for (i=0; i< (2*n)-1; i++)
	{
		int row;
		if (i<n)
		{
			row = n+i;
		}else{
			row=2*n-(i-n)-2;
		}

		for (j=0; j<row; j++)
		{
			if(j+i<n-1||i-j>=n){
				printf(" ");
			}else{
				printf("*");
			}
		}
		
		printf("\n");
	}

	int x;
	n=3;
	x=4;
	for(i=0;i<n;i++)
	{
		for(j=0;j<x;j++)
		{
			if(j*i==0||j==x-1||i==n-1){
			printf("*");
		}else{
			printf(" ");
		}
		}
		printf(" ");
		for (j=n+1;j<=2*n;j++)
		{
			if (j==n+1||j==2*n||i==0||i==n-1)
			{
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}



	char *name = "Cazhia";
	printf("%s \n", name);

	printf("Binary AND %d \n", (44&14));
	printf("Binary OR %d \n", (44|14));
	printf("Binary XOR %d \n", (44^14));
	printf("Binary one's complement %d \n", (~54));
	printf("Binary Shift to right %d \n", (44>>2));
	printf("Binary Shift to left %d \n", (44<<2));

	// printf("Enter an int: \n");
	// scanf("%d", &n);

	// for(i=1; i<=n; i++)
	// {
	// 	if(n%i==0)
	// 	{
	// 		printf("%d,",i);
	// 	}
	// }

	for (i=0; i<2*n-1; i++)
	{
		for (j=0; j<n; j++)
		{
			if((j+i >= n-1 && i<n)||(j!=0 && i>=n)){
				printf("* ");
			}else{
				printf(" ");
			}
		}
		
		printf("\n");
	}


}


// *   *    *
//  *  *   *
//   * *  *
//    ** *
// **********
//     **
//    ** *
//   * *  *
//  *  *   *
// *   *    *


// 0	012345
// 1	0123456
// 2	01234567
// 3	012345678
// 4	0123456789
// 5	012345678910
// 6	01234567891011
// 7	012345678910
// 8	0123456789
// 9	012345678
// 10	01234567
// 11	0123456
// 12	012345