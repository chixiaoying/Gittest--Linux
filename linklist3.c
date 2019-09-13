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

void insert(struct Student *head)
{
	int i,order;
	struct Student *q = head;// the current linklist
	struct Student *q2 = (struct Student*) malloc(LEN);
//	struct Student *q2 = &p;
//	q2 = &p;//the new student
	printf("the number and score of the student:like 161403305,150.\n");
	scanf("%d,%f",&q2->num,&q2->score);
	q2->next = NULL;
	printf("Please enter the order!(a int number)\n");
	scanf("%d",&order);
	if (order>n) 
	{
		printf("enter flase");
		exit(1);
	}
	else{
		for(i=0;i<order-1;i++)
		{
			q =q->next;
		}
	}
//	printf("1:%d\n",q2->num);
	q2->next = q->next;
//	printf("2:%d 5:%d\n",q2->num,q2->next->num);
	q->next = q2;
//	printf("3:%d 4:%d\n",q->num,q->next->num);
}

void printall(struct Student *head)
{
	struct Student *q = head;
	if(q != NULL)
	{
		do
		{
			printf("%ld,%5.1f\n",q->num,q->score);
			q = q->next;
		}while(q != NULL);
	}
}

int main()
{
	struct Student *head;
	int adjust = 0;
	head = creat();
	char c[10];
	if(head!=NULL) printf("creat() complete!\n");
	while(adjust == 0)
	{
		printf("If you want to insert,enter yes otherwise enter no!\n");
		scanf("%s",c); 
		adjust = strcmp("yes",c);
		if(adjust == 0)
		{
			insert(head);
//			printf("the number and score of the student:like 161403305,150.\n");
//			scanf("%d,%f",&q1->num,&q1->score);
//			q1->next = NULL;
//			insert(q1,q);
		}
	}
	printall(head);
	return 0;
}





