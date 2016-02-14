#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int countSubarrays(int * array, int size);
int countSubarrays_optimized(int * array, int size);

int main() {
	int array[] = {1,2,8,7,6,9,10};
	cout<<"\nNumber of Subarrays = "<<countSubarrays(array, (int)sizeof(array)/sizeof(int));	
	cout<<"\nNumber of Subarrays = "<<countSubarrays_optimized(array, (int)sizeof(array)/sizeof(int));	


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
/*	if a1,a2,a3,...an is sorted and has legth len
 *	then number of strictly increasing subarrays = len*(len-1)/2  
 *	***************************************************************/

int countSubarrays_optimized(int * array, int size){
	int count = 0;
	int len = 1;
	for (int i=0; i<size-1; i++) {
		
		if (array[i+1] > array[i]) 
			len++;
		else {
			count += len*(len-1)/2;
			len = 1;
		}
	}
	
	count += len*(len-1)/2; /*this is for last subarray */
	return count;	
} 
