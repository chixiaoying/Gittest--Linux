#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int m,n,i;
	//const char *msg = "fwrite()/fread()/fgets()/fputs()/fscanf()/fopen()/fclose()";
	const char* msg = "fwrite()/fread()";
	FILE* fp = NULL;
	//fp = fopen("/root/thec/iotest.txt","r+");       //now fp is pointing the first character of the iotest.txt
	if(!(fp = fopen("/root/thec/iotest/iotext.txt","w+")))
	{
		printf("stream open 1 error!\n");
		exit(0);
	}
	n = fwrite(msg,strlen(msg),1,fp);                //so this fwrite() ,recover the data in the iotest.txt
	rewind(fp);//feek(fp,0L,0);//"L" means Long int and it can be omitted because the compiler also konw it is long int.
	if(fp == NULL)
	{
		printf("fp is null!\n");
	}
	
	//if(!fclose(fp))    //if fclose() completed it return 0 otherwise return -1,however, !0 and !(-1) both equal to 1.
	if(fclose(fp) == -1)
	{
		printf("stream close 1  error!\n");
		exit(0);
	}
	fp = NULL;
	if(!(fp = fopen("/root/thec/iotest/iotext.txt","w+")))
	{
		printf("stream open 2 error!\n");
		exit(0);
	}	//three lines(12,13,18)  when ./a.out it appear segmentation Fault
	char buf[100] = {0};
	rewind(fp);
	m = fread(buf,strlen(msg)-1,1,fp);
	for(i=0;i<strlen(msg);i++)
	{
		printf("%c",buf[i]);
	}
	printf("%d,%d\n",n,m);
	n = fwrite(msg,strlen(msg),1,fp);
	rewind(fp);
	m = fread(buf,strlen(msg)-3,1,fp);
	for(i=0;i<strlen(msg);i++)
	{
		printf("%c",buf[i]);
	}
	printf("\n%d,%d\n",n,m);
	fclose(fp);
	return 0;
}

