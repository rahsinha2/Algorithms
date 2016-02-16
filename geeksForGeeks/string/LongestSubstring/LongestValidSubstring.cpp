#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>

using namespace std;

int longestValidSubString(char *);

int main(int argc, char ** argv) {
	
	cout<<"Length of longest valid subarring is : "<<longestValidSubString(argv[1])<<"\n";
	return 0;
}
int longestValidSubString(char * arr) {
	int len = strlen(arr);
	stack<int> stk;
	int result = 0;
	stk.push(-1);

	for(int i=0; i<len; i++) {
		if (arr[i] == '(')
			stk.push(i);
		else {
			stk.pop();
			if (!stk.empty()) 
				result = max(result, i - stk.top());
			else 
				stk.push(i); /* index of current substring base */
		
		}
	}
	return result;
}
