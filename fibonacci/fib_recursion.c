#include<stdio.h>
int fibonacci(int);
int main()
{
	int n = 0;
	printf("Enter number to generate fibonacci series:");
	scanf("%d", &n);
	printf("\nFib number is %d\n",fibonacci(n));
	return 0;
}
int fibonacci(int n)	
{
	if (n <=1)	{
		return 1;
	}
	return fibonacci(n-1) + fibonacci(n-2);
}
