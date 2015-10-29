#include<stdio.h>
int main()
{
	int a[10] = {45,43,77,88,55,1000,111,-3,-99,0};
	int size = sizeof(a)/sizeof(a[0]);
	int i = 0;
	int j = 0;
	int temp = 0;	
		
	for(i=0; i<size-1 ; i++)	{

		for (j=0; j<size - 1 -i; j++)	{
			
			if (a[j] > a[j+1])	{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}

	}
	
	for(i=0; i<size; i++)	
		printf("%d  ", a[i]);
	

	return 0;
}
