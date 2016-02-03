#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class node {
	public:
	int data;
	node * next;
	};
void append(node ** head, int data);	
void printList(node * head);
void kthFromLast(node * head, int k);

int main(int argc, char** argv)
{
	int k = atoi(argv[1]);
	node * head = NULL;
	append(&head,1);	
	append(&head,2);	
	append(&head,3);	
	append(&head,4);	
	append(&head,5);	
	append(&head,6);	
	append(&head,7);	
	append(&head,8);	
	append(&head,9);	
	append(&head,10);	
	append(&head,11);	
	append(&head,12);	
	printList(head);
	kthFromLast(head, k);
	return 0;
}
void append(node ** head, int data)	
{
	node * h = *head;
	node * temp = new node;
	temp->data = data;
	temp->next = NULL;
	if (*head == NULL)	{
		*head = temp;
	}
	else	{
		while(h->next != NULL)
			h = h->next;
		h->next = temp;
	}
}
void printList(node * head)
{
	node * h = head;
	while(h != NULL)	{
		cout<<h->data<<" -> ";
		h = h->next;
	}
	cout<<"NULL"<<endl;
}
void kthFromLast(node * head, int k)
{
	int index = k;
	if(head == NULL)	{
		cout<<"\nLink List is empty\n";
		return;
	}
	node * h = head;
	node * ptr = head;
	while(ptr->next != NULL && k-- > 1)	{
		ptr = ptr->next;
	}
	
	if ((ptr->next == NULL && k>1) || index<1)	{
		cout<<"\nIndex out of bound\n";
		return;
	}

	while(ptr->next != NULL)	{
		h = h->next;
		ptr = ptr->next;
	}	
	cout<<"\n"<<index<<"th element from last is = "<<h->data<<"\n";
}

