#include<iostream>
#include<limits.h>
#include<stdlib.h>

using namespace std;

class myStack {
	int * arr;
	int * next;
	int * top;
	int k;
	int n;
	int free_ptr;
	
	public:
	
	myStack(int k1, int n1);
	bool isFull();
	bool isEmpty(int sn);
	void push(int sn, int data);
	int pop(int sn);
	void printStack();
};
myStack::myStack(int k1, int n1) {
	k = k1;
	n = n1;
	arr = new int[n];
	next = new int[n];
	top = new int[k];

	for (int i=0; i<(n-1); i++) {
		next[i] = i+1;
	}
	next[n-1] = -1;
	
	for (int i=0; i<k; i++) {
		top[i] = -1;
	}
	free_ptr = 0;
}
bool myStack::isFull() {
	return (free_ptr == -1);
}
bool myStack::isEmpty(int sn) {
	return (top[sn] == -1);
}
void myStack::push(int sn, int data) {
	
	if (isFull()) {
		cout<<"\nStack Overflow\n";
		return;
	}
	int i = free_ptr;
	free_ptr = next[i];
	next[i] = top[sn];
	top[sn] = i;
	arr[i] = data;
	printStack();
}
int myStack::pop(int sn) {
	
	if (isEmpty(sn)) {
		cout<<"\nStack Underflow\n";
		return INT_MAX;
	}
	
	int i = top[sn];
	top[sn] = next[i];
	next[i] = free_ptr;
	free_ptr = i;	
	printStack();
	return arr[i];
}
void myStack::printStack() {
	cout<<"\nTops\n";
	for(int i=0; i<k; i++)	{
		cout<<top[i]<<" ";
	}
	cout<<"\nStack\n";
	for(int i=0; i<n; i++)	{
		cout<<arr[i]<<" ";
	}
	cout<<"\nNext\n";
	for(int i=0; i<n; i++)	{
		cout<<next[i]<<" ";
	}
	cout<<"\n==========================\n";
}	
/* argv[1] = k (no of stacks), argv[2] = n (size of array) */
int main(int argc, char ** argv) {

	int k = atoi(argv[1]);
	int n = atoi(argv[2]);
	myStack kStack(k,n);
	kStack.push(0, 11);
	kStack.push(0, 22);
	kStack.push(1, 33);
	kStack.push(2, 77);
	kStack.pop(0);
	kStack.push(2,9999);

	return 0;
}
