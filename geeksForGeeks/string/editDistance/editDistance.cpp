#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

void editDistance(string , string);

int main(int argc, char ** argv) {

	editDistance(argv[1], argv[2]);
	return 0;
}
void editDistance(string str1, string str2)
{
	int len1 = str1.length();
	int len2 = str2.length();
	
	if (abs(len1 - len2) > 1) {
		cout<<"Edit distance is not one!!";
		return;
	}
	int edits = 0;
	if (len1 == len2) { /* equal length */ 
	
		for(int i=0;i<len1; i++) {
			if (str1[i] != str2[i]) {
				edits++;
				if (edits > 1) {
					break;
				}
			}
		}
		
	} else {
		if (len2 > len1) 
			swap(str1,str2); /* so that st1 is always longer */
		len1 = str1.length();	
		for (int i=0; i<len1; i++) {
			if (str1[i] != str2[i]) {
				edits++;
				str1.erase(i,1); /* erases character in long string */
				i--;		 /* reduce index so that same char in small string */
						 /* is compared again with the new char in big string */
				if (edits > 1)
					break;
			}
		}
	}

	if (edits == 1) {
		cout<<"Edit distance is one!!";
		return;
	} else {
		cout<<"Edit distance is not one!!";
		return;
	}
}
