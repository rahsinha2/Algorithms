#include<iostream>
#include<stack>
#include<vector>
#include<stdio.h>

using namespace std;
class sortStack {
	stack<int> stack1; /* original stack  */
	stack<int> stack2; /* auxiliary stack */
	
	public:
	sortStack();
	void push1(int data);
	void push2(int data);
	void sort(); 
	void printStack();
};

sortStack::sortStack() {
	stack1.push(100);
	stack1.push(50);
	stack1.push(1);
	stack1.push(200);
	stack1.push(900);
	stack1.push(-55);
	stack1.push(33);
}
void sortStack::push1(int data) {
	stack1.push(data);
}
void sortStack::push2(int data) {
	stack2.push(data);
}
void sortStack::sort() {

	while (!stack1.empty()) {
	
		int x = stack1.top();
		stack1.pop();
		
		while(!stack2.empty() && stack2.top() > x) {
			int y = stack2.top();
			stack2.pop();
			stack1.push(y);

		}
		stack2.push(x);	
	}
}
void sortStack::printStack() {
	while(!stack2.empty()) {
		cout<<stack2.top()<<" ";
		stack2.pop();
	}
}
int main() {
	sortStack stk;
	stk.sort();  /* O(n*n) time O(n) space complexity */
	stk.printStack();
	return 0;
}
