#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>

using namespace std;

typedef struct edge {
	int u;
	int v;
} edge;

int visited[50];
vector<int> graph[50];
void init_visited();
void DFS(int);

int main(int argc, char ** argv)
{
	int numEdge = 10;
	int u = 0;
	int v = 0;
	int p = atoi(argv[1]);
	int q = atoi(argv[2]);
	int flag = 0;
	if(p<0 || p>9){	
		cout<<p<<": node deos not exist in graph\n";
		flag++;
	}
	if(q<0 || q>9) {	
		cout<<q<<": node deos not exist in graph\n";
		flag++;
	}
	if(flag>0)
		exit(1);

	init_visited();
	edge listOfEdges[10] = {{0,1},{1,2},{2,3},{1,3},{7,6},{6,8},{8,9},{9,6},{5,4},{4,3}};

	for(int i=0; i<numEdge; i++)	{
		u = listOfEdges[i].u;
		v = listOfEdges[i].v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int i=0; i<50; i++)	{
		if(graph[i].size() == 0)	
			continue;

		cout<<i<<":";
		for(vector<int>::iterator vi = graph[i].begin(); vi != graph[i].end(); vi++)	{
			cout<< *vi << " ";
		}
		cout<<endl;
	}

	DFS(p);
	if(visited[q] == 1)	
		cout<<p<<" and "<<q<<" are connected ";
	else
		cout<<p<<" and "<<q<<" are not connected ";

	return 0;
}
void DFS(int u)
{
	if(visited[u] == 1)	
		return;

	visited[u] = 1;

	for(vector<int>::iterator vi = graph[u].begin(); vi != graph[u].end(); vi++)	{
		DFS(*vi);
	}
}
void init_visited()
{
	for(int i=0; i<50; i++)	{
		visited[i] = 0;
	}
}
