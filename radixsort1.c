#define KeySize 3	//the amount of the key
#define Radix 10	//the quantity of the radix number(This is number so it is 0~9 is 10)
typedef int Status;
typedef char *InfoType;
typedef int KeyType;//the type of the key

typedef struct
{
	KeyType key;	//key
	InfoType otherinfo;	//other information
}RedType;
//the structure of the linklist node

typedef struct LNode
{
	RedType data;
	struct LNode *next;
}LNode,*QueuePtr,*LinkList;
//determine the linklist


void Distrubute(LinkList &L,LinkQueue B[],int j)
{
	int i,k;
	LNode *p;
	while(L->next)
	{
		p=L->next;
		L->next=p->next;//delete this node from linklist
		p->next=NULL;//
		k=p->data.key;
		for(i=1;i<j;i++)
			k/=10;
		k=k%10;
		enQueue(B[k],p);
	}
}

void Collect(LinkList &L,LinkQueue B[])
{
	int i,j=-1;
	for(i=0;i<Radix;i++)
	{
		if(!QueueEmpty(B[i]))
		{
			if(j!=1)
				B[j].rear->next=B[i].front->next;
			else
				L->next=B[i].front->next;
			j=i;
		}
	}
	for(i=0;i<Radix;i++)
	{
		B[i].rear=B[i].front;
		B[i].front->next=NULL;
	}
}



int main()
{

	Collect();
	return 0;
}










void RadixSort(LinkList &L)
{
	LinkQueue B[Radix];
	int i;
	for(i=0;i<Radix;i++)
		InitQueue(B[i]);
	for(i=1;i<=KeySize;i++)
	{
		Distribute(L,B,i);
		Collect(L,B);
	}
}














