#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

using namespace std;

int reverse(int x); 

int main(int argc, char ** argv)
{
	cout<<reverse(atoi(argv[1]))<<"\n";
	return 0;
}
/************************************************
 * we will return zero if integer given = 0
 * or if there is overflow cosidering the size of
 * integer depending on machine architecture
 * **********************************************/

int reverse(int x) 
{
    if(x==0)
        return 0;
    
    int reversed = 0;
    
    while(x!=0)  {
        if (reversed > (INT_MAX/10) || reversed < (INT_MIN/10))
            return 0;
        reversed = (reversed * 10) + (x%10);
        x = x/10;
    }
    return reversed;    
}
