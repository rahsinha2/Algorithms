#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node * left;
	struct node * right;
	} node;
void insert(node ** root, int data);
void inorder(node * root);
int search(node * root, int data);
int menu();

int main()
{
	node * root = NULL;
	int choice = 1;
	int element = 0;
	while(choice)	{
		choice = menu();
		switch(choice)	{
		
			case 1:	printf("\nEnter element to insert : ");
				scanf("%d",&element);
				insert(&root,element);
				break;
	
			case 2:	printf("\nEnter element to search : ");
				scanf("%d",&element);
				if (search(root,element))
					printf("\n%d found in BST\n",element);
				else 
					printf("\n%d not found in BST\n",element);
				break;

			case 3:	printf("\nPrinting Inorder Travelsal of BST\n");
				inorder(root);
				break;

			case 4:	choice = 0;
				break;

			default:printf("\nInvalid options entered!!!!!!\n");	
				choice = 1;
				break;
		}
	}




	return 0;
}
int search(node * root, int data)
{
	if (!root)
		return 0;
	if(root->data == data)
		return 1;
	if(data < root->data)
		return(search(root->left, data));
	else
		return(search(root->right, data));
	
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
void inorder(node * root)
{
	if (!root)
		return;
	inorder(root->left);
	printf("%d  ", root->data);
	inorder(root->right);
	
	return;
}
int menu()
{
	int choice = 0;
	printf("\n\n1.Insert Element");
	printf("\n2.Search Element");
	printf("\n3.Print Inorder");
	printf("\n4.Exit\n");
	printf("\nEnter ur choice:");
	scanf("%d",&choice);
	return choice;
}
