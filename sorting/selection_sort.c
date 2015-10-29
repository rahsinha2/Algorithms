#include<stdio.h>
int main()
{
	int a[10] = {33,44,-1,0,19,11,1000,99,4000,-44};	
	int size = sizeof(a)/sizeof(a[0]);
	int i = 0;
	int j = 0;
	int temp = 0;
	int smallest_index = 0;
	for (i=0; i<size-1; i++)	{
	
		smallest_index = i;
		for(j=i+1; j<size; j++)	{
			if(a[j] < a[smallest_index])	{
				smallest_index = j;
			}
		}		

		temp = a[i];
		a[i] = a[smallest_index];
		a[smallest_index] = temp;
		

	}

	for (i=0; i<size; i++)	{
		printf("%d  ", a[i]);
	}
	return 0;
}
