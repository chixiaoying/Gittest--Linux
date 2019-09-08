#include<stdio.h>
#include<string.h>

typedef struct 
{
	int a;
	char b[10];
	int  num;
}structure;

int main()
{
	structure *s;
	structure st[2] = {{1,"dudezheng",161403305},{2,"chiying",111111111}};
	printf("%d,%s,%d\n",st[0].a,st[0].b,st[0].num);
	
	s = st;
	printf("%d\n",(*s).num);	//*s is equal to st
	printf("%s\n",s->b);	//s-> is equal to str.
	s++;
	printf("%s\n",s->b);	//s-> is equal to str.

	structure *s1;	
	s1 = (structure*)st[0].b;
	printf("%s\n",s1);
	printf("%s\n",s1+1);

	return 0;
}
