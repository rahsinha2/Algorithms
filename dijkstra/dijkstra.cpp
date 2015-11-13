#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<limits.h>

using namespace std;

typedef struct node_struct
{
	int vertex;
	int dist;
} Node;

typedef struct edge_struct
{
	int u1;
	int u2;
	int cost;
} Edge;

struct NodeCompare
{
        bool operator()(const Node &n1, const Node &n2) const
        {
        return n1.dist > n2.dist;
        }
};

vector<Node> graph[50];
int distance_array[5];
std::priority_queue<Node, vector<Node>, NodeCompare> PQ;			

int main()
{
	const int INF = INT_MAX;
	int u, v;
	int u1, u2, cost;
	int n = 5; // 5 nodes

	Edge edgeList[10] = {
				{0, 1, 10},
				{0, 3, 5},
				{1, 2, 1},
				{1, 3, 2},
				{2, 4, 4},
				{3, 1, 3},
				{3, 2, 9},
				{3, 4, 2},
				{4, 0, 7},
				{4, 2, 6}
			};

	for(int i=0; i<10; i++)	{
	
		u1 = edgeList[i].u1;
		u2 = edgeList[i].u2;
	
		Node t;
		t.vertex = u2;
		t.dist = edgeList[i].cost;
		graph[u1].push_back(t);
	}

	for (int i=0; i<n; i++) {
		u = i;
		cout << u << ": ";
		for(vector<Node>::iterator vi = graph[u].begin(); vi != graph[u].end(); ++vi)
		{		
			v = vi->vertex;
			cost = vi->dist;
			cout << "[" << v << "," << cost << "] ";
		}
		cout << endl;
		
	}
	/* Dijkstra alogo starts here */
	int k=0;
	while (k<5)	{	
	for (int i=0; i<5; i++)	
		distance_array[i] = INF;
	distance_array[k] = 0;	/* source node s is 0 and distance of s to s is 0 */
	
	Node x, current;
	x.vertex = k;	/* Assuming 0 is the source node */
	x.dist = k;
	int source = x.vertex;
	PQ.push(x); 
	while (!PQ.empty())	{
		current = PQ.top();
		PQ.pop();

	        for(vector<Node>::iterator vi = graph[current.vertex].begin(); vi != graph[current.vertex].end(); vi++)    {
			if (distance_array[vi->vertex] > distance_array[current.vertex] + vi->dist)	{

				distance_array[vi->vertex] = distance_array[current.vertex] + vi->dist;
				x.vertex = vi->vertex;
				x.dist = distance_array[vi->vertex];
				PQ.push(x);
			}			
		}
	}
	cout<<endl;
	for (int i=0; i<5; i++)	
		cout<<source<<" -> "<<i<<" = "<<distance_array[i]<<"\n";
	k++;
	}
	return 0;
}
