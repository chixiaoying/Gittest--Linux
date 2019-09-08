//some methods to determine the structure and some methods to init the structures and some to modify the structure

#include<stdio.h>
#include<string.h>

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
struct a	//determine 1 
{
	char* p;
	int data;
}a1 = {"test",99}; //init 1

struct b	//determine 2
{
	char* p;
	int data;
};

struct c	//determine 3
{
	char name[20];
	char* q;
	int num;
	struct b b2;
}c[2] ={{"DU","c1",1,{"b1",11}},{"CH","c2",2,{"b2",22}}};//init 2,3

struct d	//determine 2.1------deal with array problem
{
	char name[20];
	int grade;
	char *str;
};

void print(struct c test)//output1
{
	printf("%s,%s,%d,%s,%d\n",test.name,test.q,test.num,test.b2.p,test.b2.data);
	//printf("%s,%s,%d,%s,%d\n",test);
}

int main()
{
	//struct  crunode  crunode;
	
	crunode1.data = 99;	//modify 1
	printf("%d\n",crunode1.data); 	//output 2

	crunode1 =(struct crunode){.data = 13};  //init 4//init one of the parameter of the structure.
	
	struct crunode crunode2 = {.data = 14,.name = "crunode2"};//init 4.1   //init some members of the structure

	printf("%d\n",c[1].b2.data);	//output 3
	
	c[1]=(struct c){"Dudezheng","c3",3,{"b3",33}}; 	//modify 2
	printf("After change:");
	printf("%d\n",c[1].b2.data);    //output 3

	//scanf("%s%s%d",&c[1].name,&c[1].q,&c[1].num);
	//scanf("%s,%s,%d,%s,%d",&c[1]);   //false the address of the structure main for the parameter of the function and transmit the address of the member of the structure like: &c[1].name

	struct d d1;	//determine 2.1
	//d1.name = {'D'}; //array can't do this. int just can be modified in turn with circulation,char can  be modfied inturn with circulation and use string.h()strcmp(name,string);
	strcmp(d1.name,"dudezheng");    //modify 3
	d1.grade = 100;		
	d1.str = "aliyun";


	print(c[1]); 	//output 1
	//printf("%s,%s,%d,%s,%d\n",c[1]);
	return 0;
}





