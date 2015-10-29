#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct node {
	int data;
	struct node * next;
	} node;

void bucket_sort(int array[],int n);
void insert(node ** bucket, int data);
int bucket_index(int element);
void print_array(int array[],int n);
void init_array(int array[], int n, int range);

int main(int argc, char** argvs) /* Size of array passed as command line argument */
{
	int range = atoi(argvs[1]);	/*  Range is from 1 to range */
	if(range<10)	{
		printf("\n!!!Please enter a considerably big range > 10 for bucket sort to execute in a better way\n");
		exit(1);
	}
	int n = range/10;
	int array[n];

	init_array(array,n, range);
	bucket_sort(array,n);
	print_array(array,n);
	return 0;
}
void bucket_sort(int array[],int n)
{
	node * bucket[n];
	node * head = NULL;
	node * prev = NULL;
	int i = 0;
	int k = 0;
	int index = 0;
	for (i=0; i<n; i++)	{
		bucket[i] = NULL;
	}
	for (i=0; i<n; i++)	{
		index = bucket_index(array[i]);
		if (index>=n)
			index = n-1;
		insert(&bucket[index], array[i]);
	}
	
	for(i=0; i<n; i++)		{
		head=bucket[i];
		printf("Bucket %d--->  ",i);
		while(head)	{
			printf("%d -->  ",head->data);
			head=head->next;
		}	
		printf("\n");	
	}
	printf("\n");	
	for (i=0; i<n; i++)	{
		head = bucket[i];
		while(head)	{
			array[k++] = head->data;
			prev = head;
			head = head->next;
			free(prev);
			prev = NULL;
		}
	}	

		
}
void insert(node ** bucket, int data)
{
	node * temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	if (!(*bucket))	{
		*bucket = temp;
		return;
	}
	
	if ( data < (*bucket)->data)	{	// element less than first in node
		temp->next = (*bucket);
		*bucket = temp;
		return;

	}	
	
	node * head = *bucket;
	while(head->next != NULL)	{
		if(data < (head->next->data))	{
			temp->next = head->next;
			head->next = temp;
			return;
		}
		head = head->next;	
	}
	head->next = temp;
	return;
	
	
}
int bucket_index(int element)
{	if(element<10)
		return 0;
	else 
		return element/10; 
}
void print_array(int array[],int n)
{
	int i = 0;
	printf("Final Sorted Array after Bucket sort\n");
	printf("=====================================\n");
	for (i=0; i<n ; i++ )	
		printf("%d  ", array[i]);
	printf("\n\n");	
}
void init_array(int array[],int n, int range)
{
	int i = 0;
	srand ( time(NULL) );
	for (i=0; i<n ; i++ )	
		array[i] = rand() % range + 1;
}

