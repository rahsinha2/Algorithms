#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void print_cache();
int LCS( int, int, char *, char*);
int MAX(int a,int b);
int main(int argc, char ** argv)
{
	int ROW = 0;
	int COL = 0;
	int x = 0;
	if (argc == 3)	{
		ROW = (int)strlen(argv[1]);
		COL = (int)strlen(argv[2]);
		x = LCS(ROW, COL, argv[1], argv[2]);
	}

	else if(argc == 1){
		char str1[] = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
		char str2[] = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
		ROW = (int)strlen(str1);
		COL = (int)strlen(str2);
		x = LCS(ROW, COL, str1, str2);
	}
	else	{
		printf("\nEnter 2 arguments or none for default strings\n\n");
		exit(0);
	}
	
	printf("\nLCS length = %d\n", x);
	return 0;

}
int LCS(int ROW, int COL, char* str1, char* str2)
{
	int cache[ROW+1][COL+1];
	int i = 0;
	int j = 0;
	for (i=0; i<=ROW; i++)
		for (j=0; j<=COL; j++)
			cache[i][j] = -1;

	for (i=0; i<=ROW; i++)	{
		for (j=0; j<=COL; j++)	{
			if (i == 0 || j == 0)
				cache[i][j] = 0;
	
			else if (str1[i-1] == str2[j-1])	
				cache[i][j] = 1 + cache[i-1][j-1];	
				
			else
				cache[i][j] = MAX(cache[i-1][j], cache[i][j-1]);
		}	
	}
	
	for (i=0; i<=ROW; i++)	{
		for (j=0; j<=COL; j++)
			printf("%d  ", cache[i][j]);
	
		printf("\n");	
	}

	int index = cache[ROW][COL];
	char * string = (char*)malloc(index+1);
	memset(string, '0', index+1);
	string[index] = '\0';
	i = ROW;
	j = COL;
	while(i>0 && j>0)	{
		if(str1[i-1] == str2[j-1])	{
			string[--index] = str1[i-1];
			i--;	
			j--;
		}
		else if(cache[i-1][j] > cache[i][j-1])	
			i--;
		else
			j--;


	}

	printf("\nLCS string = %s\n",string);
	free(string);
	return cache[ROW][COL];
}

int MAX(int a, int b)
{
	return (a>b?a:b);
	
}
