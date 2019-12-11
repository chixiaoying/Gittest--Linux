#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	char *filename = "/root/thec/iotest/iotest.txt";
	FILE *p = NULL;
	if(!(p = fopen(filename ,"w")))
	{
		printf("123\n");
	}
	n = fclose(p);  //if it complete return 0 otherwise return -1;
	printf("%d\n",n);
	if(n) printf("1\n");  //is ()>0 it will run
	if(!n) printf("2\n"); // !0 > 0 
	//if(!fclose(p))
	//	printf("4");
	return 0;
}
