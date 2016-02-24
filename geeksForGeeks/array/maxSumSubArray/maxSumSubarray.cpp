#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
int maxSumSubarray(int * arr, int size);
int maxSumSubarray_negative(int a[], int size);

int main(int argc, char ** argv) {
	int arr[] = {-2, -3, 14, -1, -2, 5,-1, 7};
	for (int i=0; i<8; i++)
		cout<<arr[i]<<" ";

	cout<<endl;
//	cout<<"\n\nANSWER = "<<maxSumSubarray(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
	cout<<"\n\nANSWER = "<<maxSumSubarray_negative(arr, sizeof(arr)/sizeof(arr[0]));

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
int maxSumSubarray_negative(int a[], int size)
{
	int curr_max = a[0];
	int max_so_far = a[0];

	for(int i=1; i<size; i++) {
		curr_max = max(a[i], curr_max+a[i]);
		max_so_far = max(max_so_far,curr_max);
	}
	return max_so_far;


}
