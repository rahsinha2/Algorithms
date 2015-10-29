#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buffer[200];
	char read_buffer[200];
	FILE * fp = NULL;
	memset(buffer,'\0',200);
	memset(read_buffer,'\0',200);
	

	printf("Enter test to write into file :");
	fgets(buffer, 200, stdin);

	fp = fopen("abc.txt", "w+");
	if (!fp)	{
		printf("File operation failed");
		exit(1);
	}	

	fwrite(buffer , 1 , strlen(buffer), fp );	
	fseek(fp, 0, SEEK_SET);

	fread(read_buffer, sizeof(read_buffer), 1, fp);
	printf("\nContent read from file = %s\n",read_buffer);
	fclose(fp);
	return 0;
}
