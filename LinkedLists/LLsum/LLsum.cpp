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
void sum(node * head1, node * head2, node ** sumHead);

int main(int argc, char** argv)
{
	node * head1 = NULL;
	node * head2 = NULL;
	node * sumHead = NULL;
	append(&head1,1);	
	append(&head1,2);	
	append(&head1,9);	
	append(&head1,9);	
	append(&head1,8);	
	append(&head1,6);	
	append(&head2,2);	
	append(&head2,9);	
	append(&head2,9);	
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
        int sum = 0;

        while(head1 != NULL || head2 != NULL)   {
                sum = (head1 ? head1->data:0) + (head2 ? head2->data:0) + carry;
                append(sumHead, sum%10);
                carry = sum/10;

                if (head1)
                        head1 = head1->next;
                if (head2)
                        head2 = head2->next;
        }

        if(carry>0)
                append(sumHead, carry);
}
