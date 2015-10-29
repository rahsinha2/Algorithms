#include<stdio.h>
#include<stdlib.h>

int main(int argc, char ** argv)

{

	int * array;
	int i = 0;
	int n = atoi(argv[1]);
	array = (int*) malloc (n * sizeof(int));


	for( i =0; i<n; i++ )	{
		printf("Enter element %d :", i+1);
		scanf("%d", &array[i]);

	}

	int minval = array[0];
	printf("%d\t",array[0]);
	for (i = 1; i<n; i++)	{
		if (minval > array[i])
			minval = array[i];
		printf("%d\t",array[i]);
	}
	
	printf("\n\nMin value is = %d\n",minval);
	free(array);
	return 0;
}
