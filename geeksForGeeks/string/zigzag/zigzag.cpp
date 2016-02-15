#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void zigzag(string , int);
int findRow(int, int);

int main(int argc, char ** argv) {

	zigzag(argv[1], atoi(argv[2]));
	return 0;
}
void zigzag(string arr, int rows)
{
	if (rows == 1) {
		cout<<arr<<endl;	
		return;
	}
	string zz[rows];
	int len = arr.length();
	int rn = 0;
	for (int i=0; i<len; i++) {
		zz[rn] += arr[i];
		rn = findRow(rn,rows);
	}

	for (int i=0; i<rows; i++)
		cout<<zz[i];	
	cout<<endl;
}
int findRow(int rn, int rows) {
	static int increase = 1;
	if (rn == 0) 
		increase = 1;
	else if (rn == rows-1) 
		increase = 0;
	
	if (increase == 1)
		rn++;
	else 
		rn--;
	return rn;
}
