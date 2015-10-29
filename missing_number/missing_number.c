#include<stdio.h>
int main()
{
	int arr[10] = {1,2,3,4,5,6,7,0,9,10};
	int x1=0,x2=0;
	int i = 0;
	
	for(i=0; i<10; i++){	
		x1 = x1 ^ arr[i];
	}
	for(i=1; i<=10; i++){	
		x2 = x2 ^ i;
	}

	printf("\nMissing number is %d\n", x1^x2);
	return 0;
}
