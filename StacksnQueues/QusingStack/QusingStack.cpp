#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
using namespace std;

class myQueue {
	vector<int> stack1;
	vector<int> stack2;
	unsigned int size;
	public:

	myQueue(int size) {
		this->size = size;
	}
	void enQ(int data) {
		if(stack1.size() == size) {
			cout<<"\nOverflow";
			return;
		}	
		stack1.push_back(data);
	}

	int deQ() {
		if(stack1.empty() && stack2.empty()) {
			cout<<"\nQueue is empty";
			return INT_MAX;
		}
		int x;
	
		if(stack2.empty()) {	
			while(!stack1.empty()) {
				x = stack1.back();
				stack1.pop_back();
				stack2.push_back(x);
			}
			x = stack2.back();
			stack2.pop_back();
			return x;
		}
			
		x = stack2.back();
		stack2.pop_back();
		return x;
			
	}
	void printQueue() {
		for (vector<int>::iterator it = stack1.begin() ; it != stack1.end(); ++it)
    			cout<<*it<<" ";
		std::vector<int>::iterator rit = stack2.begin();
		cout<<"\n";
  		for (; rit!= stack2.end(); ++rit)
    			cout<<*rit<<" ";
		cout<<"\n";
	}
};

int main()
{
	myQueue q(5);
	q.enQ(1);
	q.enQ(2);
	q.printQueue();
	q.enQ(3);
	q.printQueue();
	q.enQ(4);
	q.printQueue();
	q.enQ(5);
	q.printQueue();
	cout<<"\nDequeued element : "<<q.deQ()<<"\n";
	q.printQueue();
	q.enQ(6);
	q.enQ(7);
	q.enQ(8);
	q.enQ(9);
	q.enQ(10);
	q.enQ(11);
	cout<<"\nDequeued element : "<<q.deQ()<<"\n";
	q.printQueue();
	cout<<"\nDequeued element : "<<q.deQ()<<"\n";
	q.printQueue();
	cout<<"\nDequeued element : "<<q.deQ()<<"\n";
	q.printQueue();
	cout<<"\nDequeued element : "<<q.deQ()<<"\n";
	cout<<"\nDequeued element : "<<q.deQ()<<"\n";
	cout<<"\nDequeued element : "<<q.deQ()<<"\n";
	cout<<"\nDequeued element : "<<q.deQ()<<"\n";
	cout<<"\nDequeued element : "<<q.deQ()<<"\n";
	cout<<"\nDequeued element : "<<q.deQ()<<"\n";
	cout<<"\nDequeued element : "<<q.deQ()<<"\n";
	cout<<"\nDequeued element : "<<q.deQ()<<"\n";
	return 0;
}
