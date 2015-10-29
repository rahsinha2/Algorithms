#include<stdio.h>

void merge_sort(int a[], int begin, int end);
void merge(int a[], int begin, int mid, int end);	
int main()	
{
	int a[11] = {-222,44,55,22,-9,7,8,1000,3000,800,33};
	int i = 0;
	int size = sizeof(a)/sizeof(a[0]);
	merge_sort(a, 0,size-1);
	for (i=0; i<size; i++)
		printf("%d  ", a[i]);
	return 0;
}

void merge_sort(int a[], int begin, int end)
{
	int mid = (begin+end)/2;

	if (begin<end)	{
		merge_sort(a,begin,mid);
		merge_sort(a,mid+1,end);
		merge(a,begin,mid,end);		
	}
	

}

void merge(int a[], int begin, int mid, int end)	
{
	int n1 = mid - begin +1;
	int n2 = end - mid;

	int arr1[n1];
	int arr2[n2];
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0; i<n1; i++)
		arr1[i] = a[begin+i];
	for (j = 0; j<n2; j++)
		arr2[j] = a[mid+1+j];

	
	i=0;
	j=0;
	k = begin;
	while(i<n1 && j<n2)	{
	
		if (arr1[i] < arr2[j])	{
			a[k] = arr1[i];
			i++;
			k++;
		}
		else {
			a[k] = arr2[j];
			j++;
			k++;

		}
	}	

	while(i<n1)	{
		a[k] = arr1[i];
		i++;
		k++;	

	}
	while(j<n2)	{
		a[k] = arr2[j];
		j++;
		k++;	

	}




}
