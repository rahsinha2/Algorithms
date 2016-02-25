#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unordered_map>

using namespace std;
int maxSumSubarray(int * arr, int size);
int maxSumSubarray_negative(int a[], int size, int k);

int main(int argc, char ** argv) {
	int arr[] = {1,2,3,4,5,6,7,8};
	for (int i=0; i<8; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
//	cout<<"\n\nANSWER = "<<maxSumSubarray(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
	cout<<"\n\nANSWER = "<<maxSumSubarray_negative(arr, sizeof(arr)/sizeof(arr[0]), atoi(argv[1]));

	return 0;
}
/*This algo doesnot work for all (-ve) numbers in the array*/
int maxSumSubarray(int * arr, int size) {
	int sum_ending_here = 0;
	int max_so_far = 0;
	for (int i=0; i<size; i++) {
		sum_ending_here += arr[i];
		if (sum_ending_here <0) {
			sum_ending_here = 0;
		}
		else if (max_so_far < sum_ending_here)
			max_so_far = sum_ending_here;
	}
	return max_so_far;

}
int maxSumSubarray_negative(int a[], int size, int k)
{
	int result = 0;
	int sum = 0;
	unordered_map<int, int> myMap;
	myMap[0] = -1; /* if max subarray includes first element */	
	for (int i=0; i<size; i++) {
		sum += a[i];
		if (myMap.count(sum) == 0)
			myMap[sum] = i;
		if (myMap.count(sum-k) > 0)
			result = max(result, i-myMap[sum-k]);
	}
/*	Method of printing unordered map
 * 	for (auto x = myMap.begin(); x != myMap.end(); x++)  
	    std::cout << x->first << ": " << x->second << std::endl;
  */
	return result;
}
