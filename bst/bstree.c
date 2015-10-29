#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node {
	int data;
	struct node * left;
	struct node * right;
	} node;

void init_array(int array[], int size, int range);
void insert(node ** root, int data);
void print_array(int array[],int size);
void print_inorder(node * root);
/* Takes two command line arguments argv[1] = size of array, argv[2] = range of random numbers */
int main(int argc, char ** argv)
{
	int i = 0;
	int size = atoi(argv[1]);
	int range = atoi(argv[2]);
	int array[size];
	node * root = NULL;
	
	init_array(array, size, range);	/* Init array with random numbers */
	print_array(array, size);	/* Print array			  */
	
	for(i=0; i<size; i++)		/* Insert array elements into BST */
		insert(&root,array[i]);
	

	printf("\nPrinting Inorder Travelsal of BST\n");
	printf("=================================\n");
	print_inorder(root);

	return 0;
}

void insert(node ** root, int data)
{
	if (!(*root))	{
		node * temp = (node*)malloc(sizeof(struct node));
		*root = temp;
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		return;
	}
	
	if(data < (*root)->data)	
		insert(&(*root)->left, data);
	else
		insert(&(*root)->right, data);
	
	return;
}
void print_inorder(node * root)
{
	if (!root)
		return;
	print_inorder(root->left);
	printf("%d  ", root->data);
	print_inorder(root->right);
	
	return;
}
void init_array(int array[], int size, int range)
{
	int i = 0;
        srand ( time(NULL) );
        for (i=0; i<size ; i++ )
                array[i] = rand() % range + 1;	
}
void print_array(int array[],int size)
{
        int i = 0;
        printf("\nArray\n");
        printf("=====\n");
        for (i=0; i<size ; i++ )
                printf("%d  ", array[i]);
        printf("\n\n");
}
