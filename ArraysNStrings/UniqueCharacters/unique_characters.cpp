#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define ASCII_CHARACTERS 128
void bool_check_unique_characters(char * string);

int main(int argc, char ** argv)
{
	char * string = (char*)malloc(strlen(argv[1]+1));
	memset(string,0, strlen(argv[1])+1);
	strncpy(string, argv[1], strlen(argv[1]));
	string[strlen(argv[1])] = '\0';
	int len = strlen(string);
	if(len>ASCII_CHARACTERS)	{
		cout<<"\nString has duplicate Characters\n";
		free(string);	
		exit(1);
	}

	bool_check_unique_characters(string);

	for(int i=0; i<(len-1); i++)	{
		for(int j=i+1; j<len; j++)	{
			if(string[i] == string[j])	{
				cout<<"\nString has duplicate Characters\n";
				free(string);
				exit(1);
			}	
		}
	}

	cout<<"\nString has all unique characters\n";
	free(string);
	return 0;
}
void bool_check_unique_characters(char * string)
{
	bool table[128];
	for(int i=0; i<ASCII_CHARACTERS; i++)	
		table[i] = false;
	
	for(int i=0; i<(int)strlen(string); i++)	{
		if(table[(int)string[i]] == true)	{
			cout<<"\nbool_check_unique_chars:String has duplicate Characters\n";
			return;	
		}
		table[(int)string[i]] = true;
	}
	cout<<"\nbool_check_unique_chars:String has all unique characters\n";
	
}
