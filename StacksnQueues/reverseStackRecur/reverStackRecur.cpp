#include<iostream>
#include<stack>
#include<vector>
#include<stdio.h>

using namespace std;

void init(stack<int> * myStack);
void printStack(stack<int> * myStack);
void reverseStack(stack<int> * myStack);
void insertAtBottom(stack<int> * myStack, int x);

int main() {
	stack<int> myStack;
	init(&myStack);
	reverseStack(&myStack);
 	printStack(&myStack);
	return 0;
}

void init(stack<int> * myStack) {
	myStack->push(10);
	myStack->push(9);
	myStack->push(8);
	myStack->push(7);
	myStack->push(6);
	myStack->push(5);
	myStack->push(4);
	myStack->push(3);
	myStack->push(2);
	myStack->push(1);
	myStack->push(0); /* TOP */

}
void printStack(stack<int> * myStack) {

	while(!myStack->empty()) {
		cout<<myStack->top()<<" ";
		myStack->pop();
	}
}
void reverseStack(stack<int> * myStack)
{
	if(!myStack->empty()) {
		int x = myStack->top();
		myStack->pop();
		
		reverseStack(myStack);

		insertAtBottom(myStack, x);

	}
}
void insertAtBottom(stack<int> * myStack, int x)
{

	if(myStack->empty()) {
		myStack->push(x);
		return;
	}
	int y = myStack->top();
	myStack->pop();
	insertAtBottom(myStack, x);
	myStack->push(y);
}

