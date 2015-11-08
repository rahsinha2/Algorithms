#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
/* Pass dimenstion of n x n matrix as a command line */
int main(int argc, char ** argv)
{
	int n = atoi(argv[1]);
	int image[n][n];
	cout<<"\nOriginal Image\n";
	for (int i=0; i<n; i++)	{
		for(int j=0; j<n; j++)	{
			image[i][j] = rand() % 10;
			cout<<image[i][j]<<"  ";
		}
		cout<<endl;
	}	
	/* Rotate the image 90 degree clockwise here */
	int temp = 0;
	int layer = 0;
	for(layer=0; layer<(n/2); layer++)	{
		for(int i=layer; i<n-1-layer; i++)	{
			temp = image[layer][i];
			image[layer][i] = image[n-1-i][layer];
			image[n-1-i][layer] = image[n-1-layer][n-1-i];
			image[n-1-layer][n-1-i] = image[i][n-1-layer];
			image[i][n-1-layer] = temp;

		}
	}
	cout<<"\nRotated Image\n";
	for (int i=0; i<n; i++)	{
		for(int j=0; j<n; j++)	{
			cout<<image[i][j]<<"  ";
		}
		cout<<endl;
	}	
	return 0;
}
