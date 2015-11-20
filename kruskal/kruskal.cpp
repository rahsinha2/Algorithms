#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct edge_struct
{
	int u1;
	int u2;
	int cost;
} Edge;

int compare(const void *a, const void *b)
{
	return ( ((Edge *)a)->cost - ((Edge *)b)->cost );
}

int findSet(int * parent,int v);	
void makeSet(int * parent, int);
void makeUnion(int * parent, int u, int v);

int main()
{	
	int i;
	int numEdge = 14;
	int numVer = 9;
	int parent[numVer];
	Edge edgeList[14] = {	
				{0, 1, 4},
				{0, 5, 8},
				{1, 2, 8},
				{1, 5, 11},
				{2, 6, 2},
				{2, 3, 7},
				{2, 8, 4},
				{3, 4, 9},
				{3, 8, 14},
				{4, 8, 10},
				{5, 6, 7},
				{5, 7, 1},
				{6, 7, 6},
				{7, 8, 2}
			};
	/* initialize parent[i] with i */	
	makeSet(parent, numVer);
	
	/* sort the edgelist */
	qsort(edgeList, numEdge, sizeof(Edge), compare);
	cout<<"\nEdges of original graph after sorting\n";
	for (i = 0; i < numEdge; i++)	
		cout<<edgeList[i].u1<<" "<< edgeList[i].u2<<" "<<edgeList[i].cost<<endl;
		
	cout<<"\nEdges of MST\n";
	for (i = 0; i < numEdge; i++)	{
		/*check if root of both the vertices of the edge are in the same set*/
		if(findSet(parent,edgeList[i].u1) != findSet(parent, edgeList[i].u2))	{
			cout<<edgeList[i].u1<<" "<< edgeList[i].u2<<" "<<edgeList[i].cost<<endl;
			makeUnion(parent, edgeList[i].u1, edgeList[i].u2);
		}
	}
	cout<<"\nParent array\n";
	for (i=0; i<numVer; i++)
		cout<<parent[i]<<" ";
	cout<<"\n";
	return 0;
}
void makeSet(int * parent, int v)	
{
	for(int i=0; i<v; i++)	
		parent[i] = i;
}
int findSet(int * parent, int v)	
{
	while(parent[v] != v)
		v = parent[v];
	return v;
}
void makeUnion(int * parent, int u, int v)
{
	parent[findSet(parent,v)] = u;
}
