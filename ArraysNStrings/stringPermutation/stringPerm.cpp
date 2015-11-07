/* This algo runs in linear time
 *
 * another approch is sort the two strings and then compare them
 *
 * so that will be in nlogn time
 * *****************************************/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void stringPerm(char * string1, char * string2);  

/* supply two strings from command line*/
int main(int argc, char ** argv)
{
	char * string1 = (char*)malloc(strlen(argv[1]) +1 );
	char * string2 = (char*)malloc(strlen(argv[2]) +1 );
	if(strlen(argv[1]) != strlen(argv[2]))	{
		cout<<"\nDifferent String lenth. So not a permutation\n";
		return 0;
	}
	memset(string1, 0, strlen(argv[1]));
	memset(string2, 0, strlen(argv[2]));
	strncpy(string1, argv[1], strlen(argv[1]));
	strncpy(string2, argv[2], strlen(argv[2]));
	string1[strlen(argv[1])] = '\0';
	string2[strlen(argv[2])] = '\0';
	stringPerm(string1, string2);	
	free(string1);
	free(string2);
	return 0;
}
void stringPerm(char * string1, char * string2)
{
	int ASCII_table[128];
	int i=0;
	for (i=0; i<128; i++)
		ASCII_table[i] = 0;
	
	for (i=0; i<(int)strlen(string1); i++)
		ASCII_table[(int)string1[i]]++;
	
	for (i=0; i<(int)strlen(string2); i++)
		ASCII_table[(int)string2[i]]--;
	
	for (i=0; i<128; i++)	{
		if(ASCII_table[i] != 0)	{
			cout<<"\nNot a permutation\n";
			return;
		}
	}
	cout<<"\nStrings are a permutation\n";
	
	return;
} 
