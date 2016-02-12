#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

using namespace std;

class myStack {
	static const int max = 10;
	int arr[max];
	int top;
	
	public:
	myStack();
	bool isFull();
	bool isEmpty();
	void push(int data);
	int pop();
	void printStack();
};
myStack::myStack() {
	top = -1;
}
bool myStack::isFull() {
	if(top == max-1)
		return true;
	return false;
}
bool myStack::isEmpty() {
	if(top == -1)
		return true;
	return false;
}
void myStack::push(int data) {
	if(isFull())	{
		cout<<"\nStack Overflow\n";
		return;
	}
	arr[++top] = data;
	return;
}
int myStack::pop() {
	if(isEmpty()) {
		cout<<"\nStack Underflow\n";
		return INT_MAX;
	}
	top--;
	return arr[top+1];
}

void myStack::printStack() {
	if(!isEmpty())	{
		for(int i=0; i<=top; i++)	{
			cout<<arr[i]<<"  ";
		}
		cout<<"<--- TOP\n";
	}
}

class specialStack: public myStack {

	myStack min;
	public:

	void push(int data);
	int pop();
	int getMin();
};
void specialStack::push(int data) {
	if (isFull()) {
		cout<<"\nStack Overflow\n";
		return;
	}

	if (isEmpty()) {
		myStack::push(data);
		min.push(data);
		return;	
	}	
	
	myStack::push(data);
	int top_min = min.pop();
	min.push(top_min);
	if (data <= top_min) 
		min.push(data);

	return;
}
int specialStack::pop() {
	
	int x = myStack::pop();
	int y = min.pop();
	
	if (x!=y) 
		min.push(y);
	
	return x;
}
int specialStack::getMin() {
	
	int x = min.pop();
	if(x != INT_MAX)
		min.push(x);
	return x;
}

void menu();

int main()
{
	specialStack stk;
	
        int choice;
        int data;
        do{
                menu();
                cin>>choice;
                switch(choice)  {

                        case 1: cout<<"\nEnter value to push : ";
                                cin>>data;
                                stk.push(data);
                                stk.printStack();
			        break;

                        case 2: cout<<"\nPopped element is :"<<stk.pop()<<"\n";
                                stk.printStack();
                                break;

                        case 3: cout<<"Min in the stack is : "<<stk.getMin()<<"\n";
                                stk.printStack();
                                break;

                        case 4: cout<<"\nExiting\n";
                                break;

                        default:cout<<"\nInvalid Input\n";
                                break;
                }
        }
        while(choice != 4);
	
	return 0;

}
void menu()
{
        cout<<"\n1.Push\n2.Pop\n3.Get min\n4.Exit\n";
}
