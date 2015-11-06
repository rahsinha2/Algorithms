#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

void reverse(char * str);

int main(int argc, char ** argv)
{
	char string[] = "This is a string to be reversed\0";
	cout<<"\nOriginal String is = "<<string;
	reverse(string);
	cout<<"\nReversed String is = "<<string<<endl;
	
	return 0;
}

void reverse(char * string)
{
	int len = strlen(string);
	int i = 0;
	char temp;
	for (i=0; i<(len/2); i++)	{
		temp = string[i];
		string[i] = string[len-i-1];
		string[len-i-1] = temp;
	}

	if(string[len] == '\0')
		cout<<"\nThe last character in the reversed sting is a null character\n";
}

