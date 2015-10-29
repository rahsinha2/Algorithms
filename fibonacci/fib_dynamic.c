#include<stdio.h>
int main()
{
	int n = 0;
	printf("Enter number for fibonacci generation:");
	scanf("%d",&n);
	int a = 0;
	int b = 1;
	int i = 0;
	int sum = a+b;
	if(n==1)
		printf("%d ", a);
	else 
		printf("%d %d ", a, b);
	for(i=2; i<n; i++)	{
		sum = a+b;
		a=b;
		b=sum;
		printf("%d ", sum);
	}
	
	printf("\n\nNumber is %d", sum);
	
	
	
	return 0 ;
}
