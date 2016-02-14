#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;

void printSubarrays(int * array, int size);

int main() {
	int array[] = {1,2,8,7,6,9,10};
	cout<<"\nSubarrays = \n";
	printSubarrays(array, (int)sizeof(array)/sizeof(int));	
	return 0;
}
void printSubarrays(int * array, int size) {
/* In O(n*n*n)  */
	for (int i=0; i<size; i++) {
		for (int j=i; j<size; j++) {
			for (int k=i; k<=j; k++ ) 
				cout<<array[k]<<" ";
			cout<<endl;
		}
	}
}

