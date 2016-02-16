#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_CHARS 256
#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string str1, string str2);

int main(int argc, char ** argv) {

	if (isIsomorphic(argv[1], argv[2]))
		cout<<"\nThe strings are isomorphic\n";
	else
		cout<<"\nThe strings are not isomorphic\n";

	return 0;
}
bool isIsomorphic(string str1, string str2) {

	int len = str1.length();
	if (len != (int)str2.length()) {
		return false;
	}

	bool marked[MAX_CHARS] = {false};
	int map[MAX_CHARS];
	memset(map, -1, sizeof(map));
	
	for (int i=0; i<len; i++) {
	int one = str1[i];
	int two = str2[i];		
		if (map[one] == -1) {
			if (marked[two] == true)
				return false;
			
			map[one] = str2[i];
			marked[two] = true;			
		} else {
			if (map[one] != str2[i])
				return false;
		}
	}
	return true;
}
