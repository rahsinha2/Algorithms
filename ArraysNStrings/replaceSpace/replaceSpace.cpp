#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
void replaceSpace(char * string, int len);	

/*supply a string from coomand line*/

int main(int argc, char ** argv)
{
	int len = strlen(argv[1]);
	char string[1000];
	strncpy(string, argv[1], len);
	string[len] = '\0';
	replaceSpace(string, len);	
	cout<<endl<<string<<endl<<endl;
	return 0;
}
void replaceSpace(char * string, int len)
{
	int num_spaces = 0;
	int i=0;
	for(i=0; i<len; i++)
		if(string[i] == ' ')	
			num_spaces++;

	int new_len = len + (num_spaces * 2);
	string[new_len] = '\0';
	int index = len - 1;
	int index_new = new_len - 1;
	
	while(index>=0)	{
		if (string[index] == ' ')	{
			string[index_new--] = '0';		
			string[index_new--] = '2';		
			string[index_new] = '%';		
		}
		else {
			string[index_new] = string[index];
		}
		index--;
		index_new--;
	}
	return 0;
}	
