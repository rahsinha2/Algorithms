#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

class node {
	public:
	char data;
	node * next;
	};
void append(node ** head, char data);	
void printList(node * head);
void palindrome(node *head);
void reverse(node ** head);
int compareList(node * head, node * head2);
	
int main(int argc, char** argv)
{
	node * head = NULL;
	append(&head,'a');	
	append(&head,'b');	
	append(&head,'c');	
	append(&head,'c');	
	append(&head,'b');	
	append(&head,'a');		
	printList(head);
	palindrome(head);
	return 0;
}
void append(node ** head, char data)	
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
void palindrome(node *head)
{
	if(head == NULL || head->next == NULL || head->next->next == NULL)
		return;
	node * slow = head;
	node * fast = head;
	node * prev = NULL;
	node * mid = NULL;
	node * head2 = NULL;

	while(fast!=NULL && fast->next != NULL)	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	cout<<endl<<"Midle element is : "<<slow->data<<endl;
	
	if(fast != NULL) {
		mid = slow;
		slow = slow->next;
	}

	prev->next = NULL;
	head2 = slow;
	reverse(&head2);	
	if(compareList(head, head2))
		cout<<"\nGiven Linked List is a palindrome\n";
	else
		cout<<"\nGiven Linked List is not a palindrome\n";
	
	reverse(&head2);	
	
	if(mid)	{
		prev->next = mid;
		mid->next = head2;	
	} else {
		prev->next = head2;
	}
}
void reverse(node ** head)
{
	if (*head == NULL || (*head)->next == NULL)
		return;

	node * ptr1 = *head;
	node * ptr2 = ptr1->next;
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
int compareList(node * head1, node * head2)
{
	while(head1 != NULL) {
		if (head1->data == head2->data)	{
			head1 = head1->next;
			head2 = head2->next;
		}
		else 
			return 0;
		
	}
	return 1;
}
