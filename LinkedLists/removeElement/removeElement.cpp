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
void deleteElement(node ** ptr);

int main(int argc, char** argv)
{
	int k = atoi(argv[1]);	/* k is randomly forward a pointer to point to a node */
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
	node * toDelete = head;
	while(k-- >0)
		toDelete = toDelete->next;
	deleteElement(&toDelete);
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
void deleteElement(node ** ptr)
{
      /* cannot delete from empty list and also cant delete last elemnt */
	if(*ptr == NULL || (*ptr)->next ==  NULL) 
		return;

	node * temp = NULL;
	(*ptr)->data = (*ptr)->next->data;
	temp = (*ptr)->next;
	(*ptr)->next = (*ptr)->next->next;
	delete temp;	
}

