#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(char*)a - *(char*)b );
}

int main()
{
	char array[] = "kasahkjnwkjwqiuliksdnmbnmJSKJHKJDHSADHSAGDHJDKJSADNKJSAHDAGH";
        int size= (int)strlen(array);
        qsort (array, size, sizeof (char), cmpfunc);
	printf("%s\n\n",array);
	return 0;
}
