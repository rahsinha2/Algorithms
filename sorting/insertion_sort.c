#include<stdio.h>

int main()
{
	int a[10] = {66,33,99,-33,0,0,44,33,31,22};
	int i = 0;
	int j = 0;
	int size = sizeof(a)/sizeof(a[0]);
	int key = 0;
	
	
	for (i=1; i<size; i++)	{
		key = a[i];
		j=i-1;
		
		while(j>=0 && a[j]>key)	{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;

	}

	for(i=0; i<size; i++)
		printf("%d   ", a[i]);

	return 0;
}
