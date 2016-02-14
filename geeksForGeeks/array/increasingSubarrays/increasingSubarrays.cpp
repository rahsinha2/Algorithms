#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int countSubarrays(int * array, int size);

int main() {
	int array[] = {1,2,3,4,5};
	cout<<"\nNumber of Subarrays = "<<countSubarrays(array, (int)sizeof(array)/sizeof(int));	


	return 0;
}
int countSubarrays(int * array, int size) {
/* In O(m) time. m = number of subarrays */
	int count = 0;
	for (int i=0; i<size; i++) {
	
		for (int j=i+1; j<size; j++) {
			
			if (array[j] > array[j-1])
				count++;
			else
				break; 
		}
	}
	return count;
}
