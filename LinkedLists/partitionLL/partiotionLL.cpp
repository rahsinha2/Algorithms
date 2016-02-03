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
void partitionLL(node ** head, int x);

int main(int argc, char** argv)
{
	int k = atoi(argv[1]);	/* k is the pivot */
	node * head = NULL;
	append(&head,55);	
	append(&head,999);	
	append(&head,-444);	
	append(&head,0);	
	append(&head,44);	
	append(&head,200);	
	append(&head,-1000);	
	append(&head,666);	
	printList(head);
	partitionLL(&head, k);	
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
void printList(node * head)
{
	node * h = head;
	while(h != NULL)	{
		cout<<h->data<<" -> ";
		h = h->next;
	}
	cout<<"NULL"<<endl;
}
void partitionLL(node ** head, int x)
{
	if (*head == NULL || (*head)->next == NULL)
		return;
	node * h1 = NULL;
	node * t1 = NULL;
	node * h2 = NULL;
	node * t2 = NULL;
	node * h = *head;
	node * next = NULL;
	while(h!=NULL)	{
		next = h->next;
		h->next = NULL;
		if (h->data < x)	{
			if(h1 == NULL)	{
				h1 = h;
				t1 = h;
			} else {
				t1->next = h;
				t1 = h;
			}

		} else {
			if(h2 == NULL)	{
				h2 = h;
				t2 = h;
			} else {
				if (h->data == x)	{
					h->next = h2;
					h2 = h;
				} else {
					t2->next = h;
					t2 = h;
				}
			}	
		} 
		h = next;
	}

	if (h1 == NULL)	{
		*head = h2;
        }
	else if (h2 == NULL) {
		*head = h1;
	}
	else {
		t1->next = h2;
		*head = h1;
	}
}
