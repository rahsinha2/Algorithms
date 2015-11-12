#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

bool isPalindrome(int x);

int main(int argc, char ** argv)
{
	if (isPalindrome(atoi(argv[1])) == true)
		cout<<atoi(argv[1])<<" is a palindrome.\n";
	else
		cout<<atoi(argv[1])<<" is not a palindrome.\n";

	return 0;
}
/***********************************************
 * negative numbers are not palindrome
 * This is the fastest method.
 * As soon as a mismatched digit is found
 * the program terminates.
 *
 * Another approach is reversing the integer
 * But the problem is reversing an integer
 * may cause an overflow depending on 
 * integer size. So better do it this way.
 *
 * Also naive method is to represent as a string
 * and check if palindrome or not.
 ***********************************************/
bool isPalindrome(int x)
{
	if (x==0)
		return true;
	else if (x<0)
		return false;

	int div = 1;
	while(x/div >= 10)
		div *= 10;

	int left = 0;
	int right = 0;
	
	while (x!=0)	{
		left = x/div;
		right = x%10;
		if (left!=right)
			return false;
		x = (x%div)/10;
		div /= 100;
	}	
	return true;
}
