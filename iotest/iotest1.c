#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int m,n,i;
	//const char *msg = "fwrite()/fread()/fgets()/fputs()/fscanf()/fopen()/fclose()";
	const char* msg = "fwrite()/fread()";
	FILE* fp = NULL;
	if(!(fp = fopen("/root/thec/iotest/iotest.txt","r+")))  //now fp is pointing the first character of the iotest.txt
	{
		printf("fopen error!");
		exit(0);
	}	
	n = fwrite(msg,strlen(msg),1,fp);                //so this fwrite() ,recover the data in the iotest.txt
	//fclose(fp);
	//fp = NULL;
	//fp = fopen("root/thec/iotext.txt","r+");       //three lines  when ./a.out it appear segmentation Fault
	char buf[100] = {0};
	rewind(fp);
	m = fread(buf,strlen(msg)-3,1,fp);
	//n = fwrite(msg,strlen(msg),1,fp);
	for(i=0;i<strlen(msg);i++)
	{
		printf("%c",buf[i]);
	}
	printf("\n%d,%d\n",n,m);
	n = fwrite(msg,strlen(msg),1,fp);
	fclose(fp);
	//test1();
	return 0;
}

/*int test1() //just for fwrite() and fread();
{
	const char *msgtest1 = "fwrite()/fread()";
	fwrite(msgtest1,strlen(msgtest1),1,stdout);//save from msg to stdout
	//fwrite(msg,1,strlen(msg),stdout);    everytime save one charactor for strlen(msg) times (result as same as the last line)
	//stdout:a FILE* which be dentified in <stdio.h>
	char buf[10] = {0};
	//fread(buf,strlen(msg),1,stdout);//get from stdout to buf and show it
	fread(buf,1,strlen(msgtest1),stdout);
	printf("\n");
	return 0;
}
*/




