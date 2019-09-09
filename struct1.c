#include<stdio.h>
#include<string.h>
#define N 3

typedef struct 
{
	int a;
	char b[10];
	int  num;
}structure;

structure max(structure st[])
{
	int i,m=0;
	for(i=0;i<N;i++)
	{
		if(st[i].a>st[m].a)  m = i;
	}
	//printf("m is:%d\n",m);
	//printf("The maxtest is:%d,%s,%d\n",st[1].a,st[1].b,st[1].num);
	return st[m];
}

int main()
{
	structure *s;
	structure st[3] = {{1,"dudezheng",161403305},{2,"chiying",111111111},{3,"dujuzi",88888888}};
	printf("%d,%s,%d\n",st[0].a,st[0].b,st[0].num);
	
	printf("The init  is:%d,%s,%d\n ",st[1].a,st[1].b,st[1].num);
	s = st;
	printf("%d\n",(*s).num);	//*s is equal to st
	printf("%s\n",s->b);	//s-> is equal to str.
	s++;
	printf("%s\n",s->b);	//s-> is equal to str.

	structure *s1;	
	s1 = (structure*)st[0].b;
	printf("%s\n",s1);
	printf("%s\n",s1+1);
	//structure m = max(--s);		//at 34th line "s++"
	structure m = max(st);
	printf("The max is:%d,%s,%d\n ",m.a,m.b,m.num);
	return 0;
}
