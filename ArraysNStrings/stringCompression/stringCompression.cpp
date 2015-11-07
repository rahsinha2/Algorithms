#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

void compress(char * string, int len);

/*pass a string from command line*/

int main(int argc, char ** argv)
{
	int len = strlen(argv[1]);
	char string[100];
	strncpy(string, argv[1], len);
	string[len] = '\0';
	compress(string, len);
	cout<<"\nCompressed string is : "<<string<<"\n";
	return 0;
}

void compress(char * string, int len)
{
	char temp[100];
	int index = 0;
	if(len == 0)
		return;
	char * ptr = string;
	while(*ptr != '\0')	{
		int counter = 1;
		temp[index++] = *ptr;
		ptr++;
		while(*ptr == temp[index-1])	{
			counter++;
			ptr++;
		}
		sprintf(temp+index, "%d", counter);
		while(counter>0)	{
			counter /= 10;
			index++;
		}
	}
	temp[index] = '\0';	
	if(strlen(temp) < strlen(string))	{
		memset(string,0,len);
		strncpy(string, temp, strlen(temp));
		string[strlen(temp)] = '\0';
	}
	return;
}
