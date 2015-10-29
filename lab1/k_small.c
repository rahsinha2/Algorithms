#include<stdio.h>
#include<stdlib.h>

int main()

{

	int a[10] = {0,9,8,7,6,5,4,3,2,1};
	int i = 0; 
	int j = 0;
	int temp = 0;
	int k = 0;
	printf("Enter value of k between 1-10:");
	scanf("%d",&k);
	
	if(k<1 || k>10)	{
		printf("\nInvalid index\n");
		exit(1);
	}
	for (i = 0; i<9; i++)	{
	if( i == k)
		break;	
		for (j = 9; j>0+i; j--)	{
			if(a[j]<a[j-1])	{
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}

		}	

	}

	

	for(i = 0; i<10; i++)
		printf("%d\t",a[i]);
	

	printf("\n\n%dth smallest element in the array is = %d",k, a[k-1]);
	return 0;
}
