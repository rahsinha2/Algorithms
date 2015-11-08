#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

bool checkRotation(char *string1, char *string2);

/*Pass two strings as command line arguments */

int main(int argc, char ** argv)
{
	if(strlen(argv[1]) != strlen(argv[2]))	{
		cout<<"\nLength of both strings not equal. So not a rotation\n";
		return 0;
	}
	int len1 = (int)strlen(argv[1]);
	int len2 = (int)strlen(argv[2]);
	char * string1 = (char*)malloc(len1+1);
	char * string2 = (char*)malloc(len2+1);
	memset(string1, 0, len1+1);
	memset(string2, 0, len2+1);
	strncpy(string1, argv[1],len1);
	strncpy(string2, argv[2],len2);
	string1[len1] = '\0';
	string2[len2] = '\0';

	if(checkRotation(string1, string2))	
		cout<<string2<<" is a rotation of "<<string1<<"\n";
	else
		cout<<string2<<" is a not a rotation of "<<string1<<"\n";
	
	free(string1);
	free(string2);
	return 0;
}
bool checkRotation(char *string1, char *string2)
{
	char * string_concat = (char*)malloc((strlen(string2)*2) + 1);
	memset(string_concat,0,(strlen(string2)*2) +1);
	string_concat[strlen(string2)*2] = '\0';

	/* Concatenate string2 to string2 to get a new string string_concat   */

	strncat(string_concat,string2,(int)strlen(string2));
	strncat(string_concat,string2,(int)strlen(string2));

	/* Now check if string1 is a substring of the new string string_concat */

	if(strstr(string_concat, string1))	{
		free(string_concat);
		return true;
	}
	else {
		free(string_concat);
		return false;
	}
}
