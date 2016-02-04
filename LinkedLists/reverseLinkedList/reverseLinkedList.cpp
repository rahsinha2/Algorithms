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
	if (*head == NULL || (*head)->next == NULL)	{
		return;
	}
	/* This is using 3 pointers apart from the given head pointer */
/*	node * prev = NULL;
	node * curr = *head;
	node * next = NULL;

	while(curr != NULL)	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		*head = prev;

	}
*/

	/* This is using 2 pointers apart from the given head pointer */
	node * ptr1 = *head;
	node * ptr2 = (*head)->next;
		
	ptr1->next = NULL;
	
	while(ptr2->next != NULL)	{
		ptr1 = ptr2;
		ptr2 = ptr2->next;
		ptr1->next = *head;
		*head = ptr1;
	}
	ptr2->next = *head;
	*head = ptr2;

}
