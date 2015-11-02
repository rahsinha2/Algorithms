#include<iostream>
#include<stdio.h>
#include<queue>
#include<string>
using namespace std;

typedef struct node_struct
{
	char symbol;
	int freq;
	struct node_struct * left;
	struct node_struct * right;
	string code;
} Node;
struct NodeCompare
{
	bool operator()(const Node &n1, const Node &n2) const
	{		
	return n1.freq > n2.freq;
	}
};

void printTree(Node * T, int depth, string codeword);	

int main()
{

	int n = 6;
	Node nodeList[6] = {	
				{'a', 45, NULL, NULL},
				{'b', 13, NULL, NULL},
				{'c', 12, NULL, NULL},
				{'d', 16, NULL, NULL},
				{'e', 9, NULL, NULL},
				{'f', 5, NULL, NULL}
				};

	std::priority_queue<Node, vector<Node>, NodeCompare> PQ;

	for(int i = 0; i < n; ++i)
		PQ.push(nodeList[i]);
			
	for(int i = 0; i < n-1; ++i)
	{
		Node *x = new Node;
		Node *y = new Node;
		Node z;
		
		Node t;
		t = PQ.top(); 			// Getting the min item, the item still stays in the Queue		
		PQ.pop(); 			// Popping out this item		
	 	x->symbol = t.symbol;
		x->freq = t.freq;
		x->left = t.left;
		x->right = t.right;	
		
		Node u;
		u = PQ.top(); 			// Getting the min item, the item still stays in the Queue		
		PQ.pop(); 			// Popping out this item		
	 	y->symbol = u.symbol;
		y->freq = u.freq;
		y->left = u.left;
		y->right = u.right;	

		z.freq = (x->freq) + (y->freq);
		z.left = x;
		z.right = y;
		z.symbol = '/';
		x->code = "0";
		y->code = "1";
		PQ.push(z);

	}
	Node root = PQ.top();
	printTree(&root, 0, "");
	return 0;
}
void printTree(Node * root, int depth, string codeword)	
{
	if(root ==NULL)	{
		return;
	}
	if(root->symbol != '/')	{
		codeword.append(root->code);		
		cout<<"Codeword for "<<root->symbol<<" is : "<<codeword<<"\n";
	}
	else	{
		codeword.append(root->code);		
		printTree(root->left, depth+1,codeword);	
		printTree(root->right, depth+1,codeword);	
	}

}

