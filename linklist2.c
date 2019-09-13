#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Student)
struct Student
{
	int num;
	int score;
	struct Student *next;
};

//int n;
struct Student* creat()
{
	struct Student *head = NULL;
	struct Student *p1,*p2 = NULL;
//	int n = 0;
	p1 = p2 = (struct Student *)malloc(LEN);
	head = p1;
	scanf("%d %d",&p1->num,&p1->score);
	while(p1->num != 0)
	{
//		n = n+1;
		p1->next = (struct Student *)malloc(LEN);
		p1 = p1->next;
//		p2 = p2->next;
		scanf("%d %d",&p1->num,&p1->score);
	}
	p1->next = NULL;
	return(head);
}
int main()
{
	struct Student *q;
	q = creat();
	do
	{
		printf("%d %d\n",q->num,q->score);
		q = q->next;
	}while(q!=NULL);
	return 0;
}
