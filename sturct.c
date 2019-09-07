#include<stdio.h>
struct crunode
{
	struct crunode *parent;
	int data;
	char name[20];
	struct crunode *leftchild;
	struct crunode *rightchild;
}crunode1;
//in this define you can't determine the parameter.if you want to determine those you can determin at the position "a" like the next one .
// crunode is a type ,crunode1 is a parameter
struct a
{
	char* p;
	int data;
}a1 = {"test",99};

struct b
{
	char* p;
	int data;
};

struct c
{
	char name[20];
	char* q;
	int num;
	struct b b2;
}c[2] ={{"DU","c1",1,{"b1",11}},{"CH","c2",2,{"b2",22}}};

struct d
{
	char name[20];
	int grade;
	char *str;
};

int main()
{
	//struct  crunode  crunode;
	
	crunode1.data = 99;
	printf("%d\n",crunode1.data);

	crunode1 =(struct crunode){.data = 13};  //init one of the parameter of the structure.
	
	struct crunode crunode2 = {.data = 14,.name = "crunode2"};

	printf("%d\n",c[1].b2.data);
	
	c[1]=(struct c){"c3",3,{"b3",33}};
	printf("After change:");
	printf("%d\n",c[1].b2.data);


	struct d d1;
	d1.name = {'D'};
	d1.grade = 100;
	d1.str = "aliyun";

	return 0;
}





