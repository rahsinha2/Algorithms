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
void detectLoop(node *head);
	
/* Linked List with Loop 		
 *  1->2->3->4->5->6->4  this is the same 4 */

int main(int argc, char** argv)
{
	node * head = NULL;
	append(&head,1);	
	append(&head,2);	
	append(&head,3);	
	append(&head,4);	
	append(&head,5);	
	append(&head,6);	/* this points to 4 */	
 	cout<<"List 1->2->3->4->5->6->4"<<endl;
	detectLoop(head);
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

	/* Loop creation for only this program */
	/*  1->2->3->4->5->6->4  this is the same 4 */
	if(data == 6)	{
		h = *head;
		h = h->next->next->next;
		temp->next = h;
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
void detectLoop(node *head)
{
	if(head == NULL || head->next == NULL || head->next->next == NULL)
		return;
	node * ptr1 = head;
	node * ptr2 = head;
	do	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
	}
	while(ptr1 != ptr2);

	ptr1 = head;
	
	while(ptr1 != ptr2)	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	cout<<"Start point of the loop is the node with value "<<ptr1->data<<endl;
}
