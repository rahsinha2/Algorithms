#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

void onesNtwosCompliment(string number);
char flip(char bit);
/* argv[1] is  the string passed from command line */
int main(int argc, char ** argv) {

	string str(argv[1]);	
	onesNtwosCompliment(str);	
	return 0;
}
void onesNtwosCompliment(string number) {

	string ones;
	string twos;
	int len = number.length();

	for(int i=0; i<len; i++)
		ones = ones + flip(number[i]);
	twos = ones;
	int i = 0;
	for (i=len-1; i>=0; i--) {
		
		twos[i] = flip(twos[i]);
		if (twos[i] == '1')
			break;
	}	
	if (i == -1) 
		twos = '1'+twos;
	cout<<"\nOnes compliment = "<<ones;
	cout<<"\nTwos compliment = "<<twos;
}
char flip(char bit) {
	return ((bit == '1')?'0':'1');
}
