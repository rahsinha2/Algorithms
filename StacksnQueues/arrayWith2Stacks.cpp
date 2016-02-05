#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class twoStacks 
{
	int *arr;
	int size;
	int top1, top2;

	public: 
	twoStacks(int n) {
	size = n;
	arr = new int[n];
	top1 = -1;
	top2 = size;
	}

	void push1(int x) {
		if (top1 < top2-1)	
			arr[++top1] = x;
		else
			cout<<"\nStack1 Overflow\n";
		printStacks();
	}

	void push2(int x) {
		if (top2 > top1+1)	
			arr[--top2] = x;
		else
			cout<<"\nStack2 Overflow\n";
		printStacks();

	}
	void pop1() {
		if(top1 > -1)	{
			top1--;
			cout<<"\nStack 1 popped element : "<<arr[top1+1]<<"\n";
		}
		else
			cout<<"\nStack1 is empty\n";
		printStacks();
	}

	void pop2() {
		if(top2 < size)	{
			top2++;
			cout<<"\nStack 2 popped element : "<<arr[top2-1]<<"\n";
		}
		else
			cout<<"\nStack2 is empty\n";
		printStacks();

	}
	void printStacks() {
			for (int i=0; i<=top1; i++)
				cout<<arr[i]<<" ";
			cout<<"<- TOP1"<<endl;
			
			for (int j=size-1; j>=top2; j--)
				cout<<arr[j]<<" ";
			cout<<"<- TOP2"<<endl;
	}
};
void menu();
	
/* argv[1] is size of the array passed as a command lne argument */
int main(int argc, char ** argv)
{
	twoStacks stack(atoi(argv[1]));
	int choice;
	int data;
	do{
		menu();
		cin>>choice;
		switch(choice)	{

			case 1: cout<<"\nEnter value to push : ";
				cin>>data;
				stack.push1(data);
				break;

			case 2: cout<<"\nEnter value to push : ";
				cin>>data;
				stack.push2(data);
				break;

			case 3: stack.pop1();
				break;

			case 4:	stack.pop2();
				break;
			
			case 5: cout<<"\nExiting\n";
				break;

			default:cout<<"\nInvalid Input\n";
				break;
		}
	}
	while(choice != 5);
	
	return 0;
}
void menu()
{
	cout<<"\n1.Push in Stack1\n2.Push in Stack2\n3.Pop from Stack1\n4.Pop from stack2\n5.Exit\n";
}
