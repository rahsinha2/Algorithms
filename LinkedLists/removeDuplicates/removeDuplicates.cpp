#include<iostream>
#include<unordered_set>
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
void removeDuplicates(node ** head);
void removeDuplicatesHashTable(node ** head);

int main(int argc, char** argv)
{
	node * head = NULL;
	append(&head,1);	
	append(&head,1);	
	append(&head,1);	
	append(&head,1);	
	append(&head,1);	
	append(&head,1);	
	append(&head,2);	
	append(&head,3);	
	append(&head,3);	
	append(&head,5);	
	append(&head,6);	
	append(&head,6);	
	printList(head);
	//removeDuplicates(&head);    /* n square complexity */
        removeDuplicatesHashTable(&head);  /* n complexity */
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

/* This removes in n square time */
void removeDuplicates(node ** head)
{
	if (*head == NULL)
		return;
	
	node * ptr1 = *head;
	node * ptr2 = NULL;
	node * dup = NULL;

	while (ptr1!=NULL && ptr1->next!=NULL)	{
		ptr2 = ptr1;
		while(ptr2->next!=NULL)	{
			if (ptr1->data == ptr2->next->data)	{
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete dup;
			}
			else 
				ptr2 = ptr2->next;	
		}
		ptr1 = ptr1->next;
	}
}
/* This removes in O(n) linear time using hash set*/
void removeDuplicatesHashTable(node ** head)
{
	if (*head == NULL || (*head)->next == NULL)
		return;
	unordered_set<int> myset;	
	node * curr = *head;
	node * prev = NULL;
	node * dup = NULL;
	/*
	for ( auto it = myset.begin(); it != myset.end(); ++it )
        	std::cout << " " << *it;
	*/
	
	while(curr!= NULL)	{
		auto present = myset.find(curr->data);
		if(present != myset.end())	{
			prev->next = curr->next;
			dup = curr;
			curr = curr->next;
			delete dup;
		}	
		else {
			myset.insert(curr->data);
			prev = curr;
			curr = curr->next;
		}	
			
	}

}
