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
void sum(node * head1, node * head2, node ** sumHead);
int findSize(node * head);
node * addSameSize(node * head1, node * head2, int * carry);
void addCarry(node * head, node *ptr, node ** sumHead, int *carry);

int main(int argc, char** argv)
{
	node * head1 = NULL;
	node * head2 = NULL;
	node * sumHead = NULL;
	append(&head1,9);	
	append(&head1,9);	
	append(&head2,9);	
	printList(head1);
	printList(head2);
	sum(head1, head2, &sumHead);
	cout<<"Sum = \n";
	printList(sumHead);
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
void sum(node * head1, node * head2, node ** sumHead)
{
	if (head1 == NULL) {
		*sumHead = head2;
		return;
	}
	if (head2 == NULL) {
		*sumHead = head1;
		return;
	}

	int carry = 0;
		
	if (findSize(head1) == findSize(head2))	{
		*sumHead = addSameSize(head1, head2, &carry);
	} else {
		
		int diff = abs(findSize(head1) - findSize(head2));
		node * ptr = head1;
		if (findSize(head2) > findSize(head1))	{
			ptr = head2;
		}		
		
		for(int i =0; i<diff; i++)
			ptr = ptr->next;
		
		if (findSize(head2) > findSize(head1))	
			*sumHead = addSameSize(head1, ptr, &carry);
		else
			*sumHead = addSameSize(ptr, head2, &carry);
						
		if (findSize(head2) > findSize(head1))	
			addCarry(head2, ptr, sumHead, &carry);
		else
			addCarry(head1, ptr, sumHead, &carry);
	
	}

	if(carry>0) {
		node * carry_bit = new node;
		carry_bit->data = carry;
		carry_bit->next = *sumHead;
		*sumHead = carry_bit;
	}
		
}
int findSize(node * head)
{
	if(head == NULL)	
		return 0;

	int length = 0;

	while(head!=NULL)	{
		length++;
		head = head->next;
	}
	return length;
}
node * addSameSize(node * head1, node * head2, int * carry)
{
	if (head1 == NULL)
		return NULL;

	int sum=0;
	node * result = new node;
	
	result->next = addSameSize(head1->next, head2->next, carry);
	sum = head1->data + head2->data + *carry;
	*carry = sum/10;
	sum = sum%10;

	result->data = sum;
	return result;
}
void addCarry(node * head, node *ptr, node ** sumHead, int *carry)
{
	int sum = 0;
	if (head != ptr) {
		addCarry(head->next, ptr, sumHead, carry);

		sum = head->data + *carry;
		*carry = sum/10;
		sum = sum%10;

		node * newNode = new node;
		newNode->data = sum;
		newNode->next = *sumHead;
		*sumHead = newNode; 	
	}
}

