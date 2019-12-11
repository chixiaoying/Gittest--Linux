#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp = NULL;
	if((fp = fopen("test.txt","w")) == NULL)
	{
		printf("begin\n");
	}
	int i;
	int arr[7];
	printf("Please enter the array  :\n");
	for(i = 0; i < 7; i++)
	{
		scanf("%d",&arr[i]);
	}
	fp = fopen("test.txt","w");
	for( i = 0; i < 7;i++)
	{
		fprintf(fp,"%d",arr[i]);
	}
	fclose(fp);
	printf("It's OK, check the test.txt\n");
	return 0;
}
