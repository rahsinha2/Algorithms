#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
	int array[10] = {7,4,2,8,10,22,-5,88,1000,3};
        int size=10;
        qsort (array, size, sizeof (int), cmpfunc);
	int i = 0;
	for(i=0; i<size;i++)
		printf("%d->",array[i]);
	return 0;
}
