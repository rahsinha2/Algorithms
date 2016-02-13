#include<iostream>
#include<stack>
#include<vector>
#include<stdio.h>

using namespace std;

void init(stack<int> * myStack);
void printStack(stack<int> * myStack);
void sortStack(stack<int> * myStack);
void sortedInsert(stack<int> * myStack, int x);

int main() {
	stack<int> myStack;
	init(&myStack);
	sortStack(&myStack);
 	printStack(&myStack);
	return 0;
}

void init(stack<int> * myStack) {
	myStack->push(199);
	myStack->push(0);
	myStack->push(-4);
	myStack->push(55);
	myStack->push(400);
	myStack->push(900);
	myStack->push(-555);
	myStack->push(-33);
	myStack->push(-99);

}
void printStack(stack<int> * myStack) {

	while(!myStack->empty()) {
		cout<<myStack->top()<<" ";
		myStack->pop();
	}
}
void sortStack(stack<int> * myStack)
{
	if(!myStack->empty()) {
		int x = myStack->top();
		myStack->pop();
		
		sortStack(myStack);

		sortedInsert(myStack, x);

	}
}
void sortedInsert(stack<int> * myStack, int x)
{

	if(myStack->empty() || x>myStack->top()) {
		myStack->push(x);
		return;
	}
	int y = myStack->top();
	myStack->pop();
	sortedInsert(myStack, x);
	myStack->push(y);
}

