#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<math.h>

using namespace std;

void printSubsequences(int * array, int size);

int main() {
	int array[] = {1,2,8,7,6,9,10};
	cout<<"\nSubarrays = \n";
	printSubsequences(array, (int)sizeof(array)/sizeof(int));	
	return 0;
}
void printSubsequences(int * array, int size) {
/* O(n *  (2^n))  */

	unsigned int opsize = pow(2,size);
	for (int counter=1; counter< (signed)opsize; counter++) {
		for(int j=0; j<size; j++) {
			if (counter & 1<<j)
				cout<<array[j]<<" ";
		}
		cout<<endl;
	}
}

