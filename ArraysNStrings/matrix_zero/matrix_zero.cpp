#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
/* Pass dimenstion of m x n matrix as a command line */
int main(int argc, char ** argv)
{
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
	int matrix[m][n];
	cout<<"\nOriginal Matrix\n";
	/* Initialize matrix with random numbers and print*/
	for (int i=0; i<m; i++)	{
		for(int j=0; j<n; j++)	{
			matrix[i][j] = rand() % 10;
			cout<<matrix[i][j]<<"  ";
		}
		cout<<endl;
	}	
	/* Fill row and column with zero if element is zero */

	bool row[m];
	bool col[n];
	for(int i=0; i<m; i++)
		row[i] = false;
	for(int i=0; i<n; i++)
		col[i] = false;

	for (int i=0; i<m; i++)	{
		for(int j=0; j<n; j++)	{
			if (matrix[i][j] == 0)	{
				row[i] = true;	
				col[j] = true;
				break;
			}
		}
	}

	for(int i=0; i<m; i++)	{
		if(row[i] == true)	{
			for(int j=0; j<n; j++)	{
				matrix[i][j] = 0;
			}
		}
	}
	
	for(int i=0; i<n; i++)	{
		if(col[i] == true)	{
			for(int j=0; j<m; j++)	{
				matrix[j][i] = 0;
			}
		}
	}
	
	cout<<"\nOutput Matrix\n";
	for (int i=0; i<m; i++)	{
		for(int j=0; j<n; j++)	{
			cout<<matrix[i][j]<<"  ";
		}
		cout<<endl;
	}	
	return 0;
}
