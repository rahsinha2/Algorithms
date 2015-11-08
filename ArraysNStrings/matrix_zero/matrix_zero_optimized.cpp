#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

void nullifyRow(int ** matrix, int row, int n);
void nullifyCol(int ** matrix, int col, int m);
void free_matrix(int ** matrix, int row);

/* Pass dimenstion of m x n matrix as a command line */
int main(int argc, char ** argv)
{
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
	srand (time(NULL));
	int ** matrix = new int*[m];
	for(int i=0; i<m; i++)	{
		matrix[i] = new int[n];
	}
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

	bool rowHasZero = false;	/* If 1st row has a zero set true*/
	bool colHasZero = false;	/* If 1st col has a zero set true*/
	for (int i=0; i<n; i++)	{
		if (matrix[0][i] == 0)	{
			rowHasZero = true;	
		}
	}
	for (int i=0; i<m; i++)	{
		if (matrix[i][0] == 0)	{
			colHasZero = true;	
		}
	}
	/****************************************************************************
        * now consider the matrix [1][1] to [n-1][n-1].			     
	* if element[i][j] == 0 we keep a track of that in our zeroeth row and column 
 	* by setting  element[0][j] = element [i][0] = 0
 	* ***************************************************************************/
	
	for(int i=1; i<m; i++)	{
		for(int j=1; j<n; j++)	{
			if(matrix[i][j] == 0)	{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	/****************************************************************************
 	* Now we iterate through the zeroeth row and zeroeth column respectively 
 	* and nullify the corresponding columns and rows respectively
 	* ***************************************************************************/

	for(int i=1; i<n; i++)	{
		if(matrix[0][i] == 0)	{
			nullifyCol(matrix,i,m);
		}
	}
	for(int i=1; i<m; i++)	{
		if(matrix[i][0] == 0)	{
			nullifyRow(matrix,i,n);
		}
	}
	/*****************************************************************************
 	* Now nullify zeroeth row and zeroeth column depending on values of
 	* rowHasZero
 	* and
 	* colHasCol
 	* which we had set at the beginning of our operation.
 	* ***************************************************************************/
	if (rowHasZero)	
		nullifyRow(matrix,0,n);
	if (colHasZero)	
		nullifyCol(matrix,0,m);
		
	cout<<"\nOutput Matrix\n";
	for (int i=0; i<m; i++)	{
		for(int j=0; j<n; j++)	{
			cout<<matrix[i][j]<<"  ";
		}
		cout<<endl;
	}
	free_matrix(matrix, m);	
	return 0;
}
void nullifyRow(int ** matrix, int row, int n)
{
	for(int i=0; i<n; i++)	{
		matrix[row][i] = 0;
	}
}
void nullifyCol(int ** matrix, int col, int m)
{
	for(int j=0; j<m; j++)	{
		matrix[j][col] = 0;
	}
}
void free_matrix(int ** matrix, int row)
{
	for(int i=0; i<row; i++)
		delete[] matrix[i];
	delete[] matrix;
}

