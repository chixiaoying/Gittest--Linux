#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN sizeof(struct Student)
struct Student
{
	int num;
	float score;
	struct Student *next;
};

int n;

struct Student* creat(void)
{
	struct Student *head,*p1,*p2;
	p1 = p2 = (struct Student *)malloc(LEN);
	printf("the number and score of the student:like 161403305,150.\n");
	scanf("%ld,%f",&p1->num,&p1->score);
	n = 0;
	head = NULL;
	while(p1->num != 0)
	{
		n=n+1;
		if(n==1) head = p1;
		else p2->next = p1;
		p2 = p1;
		p1 = (struct Student *)malloc(LEN);
		printf("the number and score of the student:like 161403305,150.\n");
		scanf("%ld,%f",&p1->num,&p1->score);
	}//creat a crunode and scanf to it and adjust if to link it in the next circulation.
	p2->next = NULL;
	return(head);
}

void insert(struct Student *q1,struct Student *head)
{
	int i,order;
	struct Student *q = head;// the current linklist
//	struct Student p;
	struct Student *q2 = q1;
//	q2 = &p;//the new student
//	printf("the number and score of the student:like 161403305,150.\n");
//	scanf("%d,%f",&q2->num,&q2->score);
//	q2->next = NULL;
	printf("Please enter the order!(a int number)\n");
	scanf("%d",&order);
	if (order>n) 
	{
		printf("enter flase");
		exit(1);
	}
	else{
		for(i=0;i<order;i++)
		{
			q =q->next;
		}
	}
	printf("1:%d\n",q2->num);
	q2->next = q->next;
	printf("2:%d 5:%d\n",q2->num,q2->next->num);
	q->next = q2;
	printf("3:%d 4:%d\n",q->num,q->next->num);
}

int main()
{
	struct Student *q,*q1;
	struct Student p;
	q1 = &p;
	char *c;
	int adjust;
	q = creat();
	if(q!=NULL) printf("creat() complete!\n");
	printf("If you want to insert,enter yes otherwise enter no!\n");
	scanf("%s",c);
	adjust = strcmp("yes",c);
	if(adjust == 0)
	{
		printf("the number and score of the student:like 161403305,150.\n");
		scanf("%d,%f",&q1->num,&q1->score);
		//q1->next = NULL;
		insert(q1,q);
	}
	if(q != NULL)
	{
		do
		{
			printf("%ld,%5.1f\n",q->num,q->score);
			q = q->next;
		}while(q != NULL);
	}
	return 0;
}




