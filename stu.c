#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>    //support sleep(300);
//#include<windows.h>  //this is the linux and sleep() under the <unistd.h>

int k,n;
struct student
{
	double yuwen;
	double shuxue;
	double yingyu;
	double zong;
	double pingjun;
	char name[20];
	char num[20];
} stu[1000];

void jiazai(struct student stu[],int *num1);
void baocun(struct student stu[],int n);
void find(struct student stu[],int n);
int findnum(struct student stu[],int n,char *num);  //find the number of the student;
void shanchu(struct student stu[],int *num1);
void shanchuyi(struct student stu[],int *num1);    //delete one piece of the record;
void shanchuquanbu(struct student stu[],int *num1);
void tianjiayi(struct student stu[],int i);        //add one piece of the record;
void tianjia(struct student stu[],int *num1);      //add the records;
void xiugai(struct student stu[],int n);           //alter one piece of the record;
void output(struct student stu[],int n,int x);     //print the information;
void paixu(struct student stu[],int n);            //sort;
int jianchaxuehao(struct student stu[],char *num); //do validity check on  the number of the student;
int jianchachengji(double num);                    //do validity check on the grade;
void outputone(struct student *stu,int i,int x);   //print one piece of the record;
void caidan();

int main()
{
	int q;
	jiazai(stu,&n);
	caidan();
	scanf("%d",&q);
	while(q>6)
	{
		printf("Please enter again!\nPlease enter the number between 0 to 6\n");
		scanf("%d",&q);
	}
	sleep(300);
	system("cls");
	switch(q)
	{
	case 1: tianjia (stu,&n); break;
	case 2: xiugai(stu,n); break;
	case 3: paixu(stu,n); break;
	case 4: find(stu,n); break;
	case 5: shanchu(stu,&n); break;
	case 6: output(stu,n,0); break;
	case 0: exit(0);//The normal exit ;exit(1) is the abnormal eit;
	}
	return 0;
}


void caidan()
{
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| |888888888888888888888888888888888888888|\n");
	printf("|----------Welcome to the management---------| |88888888......88888888888......88888888|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| |888888...........88888...........888888|\n");
	printf("|		1:add the grade		     | |8888..............888..............8888|\n");
	printf("|		2:alter the grade	     | |888................8................888|\n");
	printf("|		3:sort			     | |8888................................888|\n");
	printf("|		4:find			     | |8888.......Mr.Du with Mrs.Chi......8888|\n");
	printf("|		5:delete		     | |88888.............................88888|\n");
	printf("|		6:show the record	     | |8888888.........................8888888|\n");
	printf("|		7:exit			     | |88888888......................888888888|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| |8888888888..................88888888888|\n");
	printf("|-----------Welcome to the management--------| |8888888888888............88888888888888|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| |8888888888888888.......8888888888888888|\n");
	printf("Please enter the choose:\n");
}


void jiazai(struct student stu[],int *num1)
{
	FILE *fp;  //be used to define a pointer for a file with buffer(file stream)
	int i;
	if((fp=fopen("//root/thec/student.bat","r"))==NULL)  //open a file(explain more in the thecfuction)
	{
		*num1 = 0;
		return;
	}
	for(i=0; fread(&stu[i],sizeof(struct student),1,fp)!=0;i++)  //get the data from the file stream "fp" (explain more in the thecfunction) 
		*num1=i;
	fclose(fp); 	//close a file stream(explain more in the thecfunction)
}


void paixu(struct student stu[],int n)
{
	int xuehao(const void *a,const void *b);
	int yuwen(const void *a,const void *b);
	int shuxue(const void *a,const void *b);
	int yingyu(const void *a,const void *b);
	int zongchengji(const void *a,const void *b);
	int (*cmp[])(const void *a,const void *b) = {xuehao,yuwen,shuxue,yingyu,zongchengji};	//general compare function(explain more int thecfunction);
	int a;
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| |888888888888888888888888888888888888888|\n");	
	printf("|----------Welcome to the sort part----------| |88888888......88888888888......88888888|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| |888888...........88888...........888888|\n");
	printf("|	1:xuehao(descending order)	     | |8888..............888..............8888|\n");
	printf("|	2:yuwen(descending order)	     | |888................8................888|\n");
	printf("|	3:shuxue(descending order)	     | |8888................................888|\n");
	printf("|	4:yingyu(descending order)	     | |8888.......Mr.Du with Mrs.Chi......8888|\n");
	printf("|	5:grade(descending order) 	     | |88888.............................88888|\n");
	printf("|					     | |8888888.........................8888888|\n");
	printf("|					     | |88888888......................888888888|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| |8888888888..................88888888888|\n");
	printf("|-----------Welcome to the sort part---------| |8888888888888............88888888888888|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| |8888888888888888.......8888888888888888|\n");
	printf("Please enter the choose:\n");
	scanf("%d",&a);
	sleep(300);
	system("cls");
	qsort(stu,n,sizeof(stu[0]),cmp[a]); //undefined
	output(stu,n,0);
}

int xuehao(const void *a,const void *b)
{
	if(strcmp(((struct student *)a)->num,((struct student *)b)->num)>0)
		return -1;
	else
		return 1;
}

int yuwen(const void *a,const void *b)
{
	return ((struct student *)a)->yuwen < ((struct student *)b)->yuwen ? 1 : -1;
}

int shuxue(const void *a,const void *b)
{
	return ((struct student *)a)->shuxue < ((struct student *)b)->shuxue ? 1: -1;
}

int yingyu(const void *a,const void *b)
{
	return ((struct student *)a)->yingyu < ((struct student *)b)->yingyu ? 1: -1;
}

int zongchengji(const void *a,const void *b)
{
	return ((struct student *)a)->zong < ((struct student *)b)->zong ? 1: -1;
}

void shanchuyi(struct student stu[],int *num1)
{
	int i,in,c;
	char y[20];
	FILE *fp;
	char str[20];
	system("cls");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~Welcome to delete part~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("Please enter the student number that you want to delete\n");
	scanf("%s",str);
	c = jianchaxuehao(stu,str);
	while(c==0)
	{
		printf("It is illegal,please enter the number again.\n");
		scanf("%s",str);
		c = jianchaxuehao(stu,str);
	}
	sleep(300);
	system("cls");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~Welcome to delete part~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	in = findnum(stu,*num1,str);
	while(in<0)
	{
		printf("The student is not exsit!\n");
		printf("enter agagin(yes--y)back to main(no--n)\n");
		scanf("%s",y);
		while(strcmp(y,"y")&&strcmp(y,"n"))
		{
			printf("Please enter y or n!\n");
			scanf("%s",y);
		}
		if(!strcmp(y,"n"))
		{
			sleep(300);
			system("cls");
			main();
		}
		sleep(300);

		//shanchuyi(stu,num1);

		system("cls");
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf("|~~~~~~~~Welcome to delete part~~~~~~~~~~|\n");
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf("Please enter the student number that you want to delete!\n");
		scanf("%s",str);
		in = findnum(stu,*num1,str);
	}
	for(i = in; i<*num1-1 ; i++)
		stu[i] = stu [i+1];
	(*num1)--;
	if ((fp = fopen("//root/thec/student.dat","w"))==NULL)
	{
		printf("false to open!\n");
		exit(0);
	}
	sleep(300);
	system("cls");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~Welcome to delete part~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("succed to delete!\n");
	baocun(stu,*num1);
	printf("continue to delete(yes--y)return to previous menu(no--n)\n");
	getchar();
	scanf("s",y);
	while(strcmp(y,"y")&&strcmp(y,"n"))
	{
		printf("Please enter y or n!\n");
		getchar();
		scanf("%s",y);
	}
	sleep(300);
	system("cls");
	if(!strcmp(y,"n"))
		main();
	if(!strcmp(y,"y"))
		shanchuyi(stu,num1);
}

void shanchuquanbu(struct student stu[],int *num1)
{
	char y[20],a[20];
	FILE *fp;
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~Welcome to delete all part~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("If you want to delete all information?(yes---y)return to main menu(no---n)\n");
	scanf("%s",y);
	while(strcmp(y,"y")&&strcmp(y,"n"))
	{
		printf("Please enter y or n\n");
		scanf("%s",y);
	}
	sleep(300);
	system("cls");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~Welcome to delete all part~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	if(!strcmp(y,"y"))
	{
		fp=fopen("/root/thec/student.bat","w");
		*num1 = 0;
		printf("complete!\n");
		fclose(fp);
		printf("return to main menu(yes---y)end(no---n)\n");
		scanf("%s",a);
		while(strcmp(a,"y")&&strcmp(a,"n"))
		{
			printf("Please enter y or n\n");
			scanf("%s",a);
		}
		sleep(300);
		system("cls");
		if(!strcmp(a,"y"))
			main();
		else
		{
			sleep(300);
			system("cls");
			return;
		}
	}
	else
	{
		sleep(300);
		system("cls");
		main();
	}

}

void shanchu(struct student stu[],int *num1)
{
	int q;
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~ Delete ~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~1.Delete some information~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~2.Delete all information~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("Please enter your choose!\n");
	getchar();
	scanf("%d",&q);
	system("cls");
	switch(q)
	{
		case 1:shanchuyi(stu,num1);break;
		case 2:shanchuquanbu(stu,num1);break;
	}
}

int findnum(struct student stu[],int n,char *num)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(stu[i].num,num)==0)
		{
			return i;
		}
	}
	return -1;
}

void baocun(struct student stu[],int n)
{
	FILE *fp;
	if((fp=fopen("/root/thec/student.bat","w"))==NULL)
	{
		printf("False to open!\n");
		exit(0);
	}
	fwrite(stu,(n+1)*sizeof(stu[0]),1,fp);
	fclose(fp);
}

void output(struct student stu[],int n,int x)
{
	int i;
	char y[20];
	if(n>0)
	{
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf("| %-10s|%-6s|%-6s|%-6s|%-6s|%-6s|%-6s |","xuehao","xingming","yuwen","shuxue","yingyu","pingjun","zongchengji\n");
		for(i=0;i<n;i++)
		{
			outputone(&stu[i],n,x);
		}
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		if(x)
		{
			char q[10];
			printf("return to main menu(yes---y) return to previous menu(no---n)");
			scanf("%s",q);
			while(strcmp(q,"y")&&strcmp(q,"n"))
			{
				printf("Please enter y or n\n");
				scanf("%s",q);
			}
			sleep(300);
			system("cls");
			if(!strcmp(q,"y"))
			{
				main();
			}
			while(!strcmp(q,"n"))
			{
				paixu(stu,n);
			}
		}
	}
	else
	{
		printf("There is no information,please to putin information!\n");
		printf("return to main menu(yes---y) end (no---n)");
		scanf("%s",y);
		while(strcmp(y,"y")&&strcmp(y,"n"))
		{
			printf("Please to enter y or n!\n");
			scanf("%s",y);
		}
		sleep(300);
		system("cls");
		if(!strcmp(y,"y"))
		{
			main();
		}
		else
			return;

	}

}

void outputone(struct student *stu,int n,int x)
{
	if(!x)
	{	
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf("| %-10s|%-6s|%-6.21f|%-6.21f|%-6.21f|%-6.21f|%-6.21f |\n",stu->num,stu->name,stu->yuwen,stu->shuxue,stu->yingyu,stu->pingjun,stu->zong);
	}
	else
	{
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf("| %-8s|%-6s|%-6s|%-6s|%-6s|%-6s|%-6s |","xuehao","xingming","yuwen","shuxue","yingyu","pingjun","zongchengji\n");
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf("| %-8s|%-6s|%-6.11f|%-6.11f|%-6.11f|%-6.11f|%-6.11f |\n",stu->num,stu->name,stu->yuwen,stu->shuxue,stu->yingyu,stu->pingjun,stu->zong);
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");	
	}
}

void tianjiayi(struct student stu[],int i)
{
	int a,b;
	printf("Please enter the student number!\n");
	getchar();
	scanf("%s",stu[i].num);
	a = jianchaxuehao(stu,stu[i].num);
	while(a==0||a==2)
	{
		if(a==0) 
			printf("the student number that you enter is illegal!Please enter again!");
		if(a==2)
			printf("the student number have been in existence!Please enter again!");
		scanf("%s",stu[i].num);
		a = jianchaxuehao(stu,stu[i].num);
		sleep(300);
		system("cls");
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf("|~~~~~~~~~~~~~~ Welcom to Student information addition part!~~~~~~~~~~~~~~~~~~|\n");
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	}
	printf("Please enter the student's name!\n");
	scanf("%s",&stu[i].name);
	printf("Please enter the student's grade of yuwen!\n");
	scanf("%1f",&stu[i].yuwen);
	b = jianchachengji(stu[i].yuwen);
	while(b==0)
	{
		printf("error!Please enter again!");
		scanf("%1f",&stu[i].yuwen);
		b = jianchachengji(stu[i].yuwen);
	}
	printf("Please enter the student's grade of shuxue!\n");
	scanf("%1f",&stu[i].shuxue);
	b = jianchachengji(stu[i].shuxue);
	while(b==0)
	{
		printf("error!Please enter again!");
		scanf("%1f",&stu[i].shuxue);
		b = jianchachengji(stu[i].shuxue);
	}
	printf("Please enter the student's grade of yingyu!\n");
	scanf("%1f",&stu[i].yingyu);
	b = jianchachengji(stu[i].yingyu);
	while(b==0)
	{
		printf("error!Please enter again!");
		scanf("%1f",&stu[i].yingyu);
		b = jianchachengji(stu[i].yingyu);
	}
	stu[i].pingjun=(stu[i].yuwen+stu[i].shuxue+stu[i].yingyu)/3;
	stu[i].zong=(stu[i].yuwen+stu[i].shuxue+stu[i].yingyu); 
}

void tianjia(struct student stu[],int *num1)
{
	char p[10] = "y",y[10];//init the string----p
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~ Welcom to Student information addition part!~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	while(!strcmp(p,"y"));
	{
		tianjiayi(stu,*num1);
		(*num1)+=1;
		printf("If continous to add(yes--y,no--n).\n");
		getchar();
		scanf("%s",p);//because p is a pointer point to the char p[10],there is no '&';
		while(strcmp(p,"n")&&strcmp(p,"y"))
		{
			printf("Please enter y or n\n");
			getchar();
			scanf("%s",p);
		}
		sleep(300);
		system("cls");
	}
	baocun(stu,*num1);
	printf("return to main menu(yes---y)end(no---n)");
	getchar();
	scanf("%s",y);
	while(strcmp(y,"n")&&strcmp(y,"y"))
	{
		printf("Please enter y or n\n");
		getchar();
		scanf("%s",y);
	}
	if(!strcmp(y,"y"))
	{
		sleep(300);
		system("cls");
		main();
	}
	else
		return;
}

void xiugai(struct student stu[],int n)
{
	int in,b,c;
	char a[10],q[10];
	char str[20],y[10];
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~ Welcom to Student information modification part!~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("Please enter the school number of the student that you want to modify!");
	getchar();
	scanf("%s",str);
	c = jianchaxuehao(stu,str);
	in = findnum(stu,n,str);
	while(c==0||(in<0&&c==1))
	{
		printf("This message is not existing!\n");
		if(c==0)
			printf("illeagal enter!Please enter again!");
		scanf("%s",a);
		while(strcmp(a,"y")&&strcmp(a,"n"))
		{
			printf("Please enter y or n\n");
			getchar();
			scanf("%s",a);
		}
		sleep(300);
		system("cls");
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf("|~~~~~~~~~~~~~ Welcom to Student information modification part!~~~~~~~~~~~~~~~|\n");
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		if(!strcmp(a,"n"))
		{
			sleep(300);
			system("cls");
			main();
		}	
		printf("Please enter the school number of the student that you want to modify!");
		scanf("%s",str);
		c = jianchaxuehao(stu,str);
		in = findnum(stu,n,str);
	}
	printf("The information before the modification!");
	outputone(&stu[in],n,1);
	printf("If modify the family name?(yes--y,no--n)\n");
	getchar();
	scanf("%s",y);
	while(strcmp(y,"y")&&strcmp(y,"n"))
	{
		printf("Please enter y or n\n");
		getchar();
		scanf("%s",y);
	}
	sleep(300);
	system("cls");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~ Welcom to Student information modication part!~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	if(!strcmp(y,"y"))
	{
		printf("Please enter the name!\n");
		scanf("%s",stu[in].name);
	}
	printf("If modify %s's grade?(yes--y)return to main menu(no--n)\n",stu[in].num);
	getchar();// it be annotation in the paper!
	scanf("%s",q);
	while(strcmp(q,"y")&&strcmp(q,"n"))
	{
		printf("Please enter y or n!\n");
		getchar();
		scanf("%s",q);
	}
	if(!strcmp(q,"y"))
	{
		printf("Please enter %s's grade of the yuwen!\n",stu[in].num);
		scanf("%1f",&stu[in].yuwen);
		b = jianchachengji(stu[in].yuwen);
		while(b==0)
		{
			printf("Error enter!Please enter again!\n");
			scanf("%1f",&stu[in].yuwen);
			b = jianchachengji(stu[in].yuwen);
		}
		printf("Please enter %s's grade of the shuxue!\n",stu[in].num);
		scanf("%1f",&stu[in].shuxue);
		b = jianchachengji(stu[in].shuxue);
		while(b==0)
		{
			printf("Error enter!Please enter again!\n");
			scanf("%1f",&stu[in].shuxue);
			b = jianchachengji(stu[in].shuxue);
		}
		printf("Please enter %s's grade of the yingyu!\n",stu[in].num);
		scanf("%1f",&stu[in].yingyu);
		b = jianchachengji(stu[in].yingyu);
		while(b==0)
		{
			printf("Error enter!Please enter again!\n");
			scanf("%1f",&stu[in].yingyu);
			b = jianchachengji(stu[in].yingyu);
		}
	}
	if(!strcmp(q,"n"))
	{
		sleep(300);
		system("cls");
		main();
	}
	baocun(stu,n);
	printf("Successfully added!\n return to main menu(yes--y) end(no--n)\n");
	getchar();
	scanf("%s",y);
	while(strcmp(y,"y")&&strcmp(y,"n"))
	{
		scanf("%s",q);
	}
	if(!strcmp(q,"y"))
	{
		//main();  //I think it should be this without next 27 lines.
		printf("Please enter %s's grade of the yuwen!\n",stu[in].num);
		scanf("%1f",&stu[in].yuwen);
		b = jianchachengji(stu[in].yuwen);
		while(b==0)
		{
			printf("Error enter!Please enter again!\n");
			scanf("%1f",&stu[in].yuwen);
			b = jianchachengji(stu[in].yuwen);
		}
		printf("Please enter %s's grade of the shuxue!\n",stu[in].num);
		scanf("%1f",&stu[in].shuxue);
		b = jianchachengji(stu[in].shuxue);
		while(b==0)
		{
			printf("Error enter!Please enter again!\n");
			scanf("%1f",&stu[in].shuxue);
			b = jianchachengji(stu[in].shuxue);
		}
		printf("Please enter %s's grade of the yingyu!\n",stu[in].num);
		scanf("%1f",&stu[in].yingyu);
		b = jianchachengji(stu[in].yingyu);
		while(b==0)
		{
			printf("Error enter!Please enter again!\n");
			scanf("%1f",&stu[in].yingyu);
			b = jianchachengji(stu[in].yingyu);
		}
	}
	if(!strcmp(q,"n"))
	{
		sleep(300);
		system("cls");
		main();
	}
	baocun(stu,n);
	printf("Successfully added!\n return to main menu (yes--y) end(no--n)\n");
	getchar();
	scanf("%s",y);
	while(strcmp(y,"y")&&strcmp(y,"n"))
	{
		printf("Please enter y or n!\n");
		getchar();
		scanf("%s",y);
	}
	if(!strcmp(y,"y"))
	{
		sleep(300);
		system("cls");
		main();
	}
	else 
		return;
}

void find(struct student stu[],int n)
{
	int in,c;
	char str[20],y[20],q[20];
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~ Welcom to Student information seeking part!~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("Please enter the school number of the student that you want to seek!\n");
	scanf("%s",str);
	c = jianchaxuehao(stu,str);
	while(c==0)
	{
		printf("Illegal school number enter!Please enter again!\n");
		scanf("%s",str);
		c = jianchaxuehao(stu,str);
	}
	sleep(300);
	system("cls");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~ Welcom to Student information seeking part!~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	in = findnum(stu,n,str);
	while(in<0)
	{
		printf("This school number is not existing!Please enter again!(yes--y) return to main menu(no--n)\n");
		getchar();
		scanf("%s",q);
		while(strcmp(q,"y")&&strcmp(q,"n"))
		{
			printf("Please enter y or n!\n");
			getchar();
			scanf("%s",q);
		}
		sleep(300);
		system("cls");
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf("|~~~~~~~~~~~~~~ Welcom to Student information seeking part!~~~~~~~~~~~~~~~~~~~|\n");
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		if(!strcmp(q,"n"))	
		{
			sleep(300);
			system("cls");
			main();
		}
		printf("Please enter the school number of the student that you want to seek!\n ");
		scanf("%s",str);
		in = findnum(stu,n,str);
	}
	sleep(300);
	system("cls");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~ Welcom to Student information seeking part!~~~~~~~~~~~~~~~~~~~|\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	if(in>=0)
	{
		printf(" %s's information:\n",str);
		outputone(&stu[in],n,1);
		printf("Continous to query(yes--y)return to main menu(no--n).\n");
		//getchar();    //paper annotation
		scanf("%s",y);
		while(strcmp(y,"y")&&strcmp(y,"n"))
		{
			printf("Please enter y or n!\n");
			//getchar();  //paper annotation
			scanf("%s",y);
		}
		sleep(300);
		system("cls");
		if(!strcmp(y,"y"))
		{
			find(stu,n);
		}
		if(!strcmp(y,"n"))
		{
			main();
		}
	}
}

int jianchaxuehao(struct student stu[],char *num)
{
	int i,f=1,g=1;
	for(i=0;num[i]!='\0'; i++)
	{
		if(num[i]<'0'||num[i]>'9')
		{
			f=0;
			break;
		}
	}
	for(i=0; i<n ; i++)
	{
		if(strcmp(stu[i].num,num)==0)
		{
			g=0;
			break;
		}
	}
	if(f==1&&g==1)
		return 1;
	else if((g==0&&f==0)||(f==0&&g==1))
		return 0;
	else if (g==0&&f==1)
		return 2;
	return 0;
}

int jianchachengji(double num)
{
	if(num<=100&&num>0)
		return 1;
	else 
		return 0;
}





























