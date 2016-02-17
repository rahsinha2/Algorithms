#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

void merge(int * arr1, int * arr2, int m, int n);

int main(int argc, char ** argv) {

	int arr1[] = {1, 5, 9, 10, 15, 20};
   	int arr2[] = {2, 3, 8, 13};
	int m = sizeof(arr1)/sizeof(arr1[0]);	
	int n = sizeof(arr2)/sizeof(arr2[0]);	
	merge(arr1, arr2, m, n);	
	cout << "After Merging \nFirst Array: ";
    	for (int i=0; i<m; i++)
        	cout << arr1[i] << " ";
    	cout << "\nSecond Array: ";
    	for (int i=0; i<n; i++)
        	cout << arr2[i] << " ";

	return 0;
}
void merge(int * arr1, int * arr2, int m, int n) {

	int last = 0;
	int j = 0;
	for (int i = n-1; i>=0; i--) {
			
		last = arr1[m-1];
		for (j = m; arr1[j-1]>arr2[i] && j>0; j--) {
			arr1[j] = arr1[j-1];	
		}
		
		if(j != m) {
			arr1[j] = arr2[i];
			arr2[i] = last;
		}

	}

}
