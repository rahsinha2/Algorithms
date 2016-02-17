#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>

using namespace std;
	
void printMinNumSequence(string str);

int main(int argc, char ** argv) {

	printMinNumSequence(argv[1]);

	return 0;
}
void printMinNumSequence(string str) {
	
	if (str.length() > 8) {
		cout<<"Invalid String length\n";
		return;
	}

	vector<int> v;
	int min_available = 1;
	int pos_of_I = 0;
	
	if (str[0] == 'I') {

		v.push_back(1);
		v.push_back(2);
		pos_of_I = 1;

	} else {
		v.push_back(2);
		v.push_back(1);
		pos_of_I = 0;
	}
	min_available = 3;
	
	for (int i=1; i<(int)str.length(); i++) {
	
		if (str[i] == 'I') {

			v.push_back(min_available);
			pos_of_I = i+1;

		} else {
			v.push_back(v[i]);
			for (int j=pos_of_I; j<=i; j++)
				v[j]++;
		}
		min_available++;
		
	}

	for (int i=0; i<(int)v.size(); i++) 
		cout<<v[i];
	cout<<endl;
}
