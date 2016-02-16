#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

void reverseString(char *);
int checkSpecial(char x);

int main(int argc, char ** argv) {

	reverseString(argv[1]);
	
	return 0;
}
void reverseString(char * arr) {
	
	if(strlen(arr) == 1) {
		cout<<arr;
		return;
	}
	int i;
	int j;
	char temp;
	for (i=0, j=(strlen(arr)-1) ; i<j; i++,j--) {
		while (checkSpecial(arr[i]))
			i++;
		while (checkSpecial(arr[j]))
			j--;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;

	}
	cout<<arr<<"\n";
}
int checkSpecial(char x) {
	if((x>=65 && x<=90) || (x>=97 && x<=122))
		return 0;
	else 
		return 1;
} 
