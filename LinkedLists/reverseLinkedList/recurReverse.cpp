#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

class node {
	public:
	int data;
	node * next;
	};
void append(node ** head, int data);	
void printList(node * head);
void reverse(node ** head);

int main(int argc, char** argv)
{
	node * head = NULL;
	append(&head,1);	
	append(&head,2);	
	append(&head,3);	
	append(&head,4);	
	append(&head,5);	
	append(&head,6);	
	printList(head);
	reverse(&head);
	printList(head);
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
void printList(node * h)
{
	//node * h = head;
	while(h != NULL)	{
		cout<<h->data<<" -> ";
		h = h->next;
	}
	cout<<"NULL"<<endl;
}
void reverse(node ** head)
{
	if (*head == NULL) {
		return;
	}
	node * first = *head;
	node * rest = (*head)->next;

	if(rest == NULL)
		return;

	reverse(&rest);
	first->next->next = first;
	first->next = NULL;
	*head = rest;
	
}
