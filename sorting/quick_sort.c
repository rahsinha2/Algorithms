#include<stdio.h>
#include<stdlib.h>

void quick_sort(int a[],int low, int high);
void printArray(int arr[], int size);
int partition(int a[],int low, int high);
int main(int argc, char ** argv)
{
	int size = atoi(argv[1]);
	int a[size];
	int i = 0;

	printf("Please enter value for the array of size %d\n\n", size);
        for (i=0; i<size; i++)  {
                printf("Enter element %d : ",i+1);
                scanf("%d", &a[i]);
        }

	quick_sort(a,0,size-1);
	printArray(a,size);
	return 0;
}
void quick_sort(int a[],int low, int high)
{
	if(low<high)	{
		int p = partition(a,low,high);
		quick_sort(a,low,p-1);
		quick_sort(a,p+1,high);
	}

}
int partition(int a[],int low, int high)
{
	int x = a[high];
	int i = low - 1;
	int j = 0;
	int temp = 0;
	for (j=low; j<=(high-1); j++)	{
		if ( a[j] <= x )	{
			i++;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;	
		}
	}
	temp = a[i+1];
	a[i+1] = a[high];
	a[high] = temp;	
	return i+1;
}
void printArray(int arr[], int size)
{
    int i;
    printf("\n");
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
