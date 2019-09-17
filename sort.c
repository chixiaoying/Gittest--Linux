#include<stdio.h>
//#include<stdlib.h>
int boss = 5201314;
#define chiying boss;
int a[] = {99,56,8,77,12,3,23,16,0,9,1,4,7,45,21};
int len = sizeof(a)/sizeof(a[0]);
int *p = a;
int bubble();
int insert();
int choose();
int shell();
void quick(int left,int right);
int heap();
void print(int b[100],int n );
void swap(int *a,int *b);
void merging(int *list1,int list1_size,int *list2,int list2_size);
void MergeSort(int k[],int n);
#define printall()  print(p,len)
void circulation();



int main()
{
	int i;
	int c=0;
	while(c<1  || c>10)
	{
		printf("please choose the methord of the sort:\n1:bubble  2: insort  3:choose   4:shell   5:quick  6:merge\n");
		scanf("%d",&c);									
		switch(c)
		{
		case 1: bubble();
			break;
		case 2: insert();
			break;
		case 3: choose();
			break;
		case 4: shell();
			break;
		case 5: quick(0,len-1);
			break;
		case 6:MergeSort(a,len);
		default: printf("error");
		}
	}
	//bubble();
	printf("if print all the number(y/n):\n");
	char ch;
	int length = -1;
//printf("a\n");
	getchar();  //it is better to put the getchar() after last scanf()
	//fflush(stdin);    //(clear the buffer area) ------not work   because gcc dong have the function; 
	//printf("%d",fflush(stdin));
	scanf("%c",&ch);   //can't run without getchar(); because scanf() do not get the char from the keyboard directly but from the buffer so if don't have getchar() the scanf get the '\n' from choose the method the user enter example '2' and a'\n' to run ,but the '\n' enter the buffer so it will be catched by the scanf() so use getchar()(to get the '\n') after every scanf() or use fflush(stdin)(clear the buffer) before every scanf()
//printf("%c",ch);
//printf("aaaaaaaaaaaa\n");
	if(ch == 'y') { printall(); }
	else{
//printf("bbbbbbbbbbbbbb\nbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb\n");
		while(length<=0 || length > len)
		{
			printf("please enter the length what you want:(0`%d)\n",len);
			getchar();
			scanf("%d",&length);
		}
		print(p,length);//for(i=0;i<len;i++) {printf("%d   ",a[i]);}
	}
	printf("Do you want to do more sort?(y/n)\n");
	char ch1;
	getchar();
	scanf("%c",&ch1);
	if(ch1 == 'y' ) { main(); }
	//printall();
	printf("Thank you for your use!\n");
	return 0;
}



void print(int b[100],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%4d",b[i]);
	}
	printf("\n");
}

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


int bubble()   //bubble sort    average:O(n^2)    bestresult:O(n)  worstresult:O(n^2)  space complexity:O(1)  stable
{  
	int i,j=0;
	int temp;
	/*for(i=0;i<len;i++)
	{
		for(j=len-1;j>i;j--)
		{
			//printf("j=%d",j);
			if(a[j]<a[j-1]) { temp = a[j-1]; a[j-1] = a[j]; a[j] = temp; }
			//printall();
		}
	}*/
	
	for(i=0;i<len;i++)
	{
		for(j=1;j<len-i;j++)
		{
			if(a[j]<a[j-1]) //{temp = a[j-1]; a[j-1] = a[j]; a[j] = temp;  }
			swap(p+j,p+j-1);
			//printall();
		}
	}
	
	//for(i=0;i<len;i++) { printf ("%d\n",a[i]); }
	return 0;
}


int insert() //insert sort      average:O(n^2)       O(n)     O(n^2)      O(1)    stable
{
	int i,temp,p;
	//printf("initial ");
	for(i = 1;i < len;i++)
	{
		temp = a[i];
		p = i-1;
		while(p >= 0 && temp < a[p])
		{
			a[p+1]=a[p];
			p--;
		}
		a[++p]=temp;
	}
	return 0;
	
}
//sort the existing array,and with i+1 the new number compared with the existing array from the last one to the first one."temp" is the number that ready to insert to the existing array; 


int choose()  //shoose sort     average:O(n^2)  bestresult:O(n^2)   worstresult:O(n^2)   space complexity:O(1)    unstable
{
	int i,j;
	for(i = 0; i<len ;i++)
	{
		for(j=i+1;j<len;j++)
		{
			int temp;
			if(a[i]>a[j])
			{
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
			}
		}
	}
	return 0;
}
//compared with the bubblesort :bubble choose the min(max) by compare the neighbor ,choosesort get the min(max) through  comparing the first number that  without sorting with the other number,if >(<) {exchange the numbers}



int shell()  //shell sort     average time complexity:O(n^2) bestresult:O(n)  worestresult:O(n^2) space complexity:O(1)      unstable
{
	int i,j,temp;
	//int len = sizeof(a)/sizeof(a[0]);
	int d = len;   //d is the length of the step
	do
	{
		d=d/3+1;
		//printf("%10d",d);
		for(i=d;i<len;i++)
		{
			temp=a[i];
			j = i-d;
			while(j>=0 && a[j]>temp)
			{
			a[j+d] = a[j];
			j -= d;
			}
			a[j+d] = temp;
		} // insert sort with a mutative d
	}while(d>1);//do{}while() do one more time than while(),because it adjust the condition after the action.it will run  at least once.
	return 0;
}  
//divide the array to several(d) shorter array to do the insert sort and the last d must be 1;it better than the insert sort and it is a kind of the insert sort that the d is mutative;Because insert sort fit the miniature data(little array),so shell sort divide the long array to several little array.

void quick(int left,int right)
{
	int i,j,k,flag;
	if(left>=right) return;
	flag = a[left];
	i = left;
	j = right;
	while (i != j)
	{
		//while(flag >= a[i] && i<j) i++;
		while(flag <= a[j] && j>i) j--;     //it(j) must be earlier than the (i)
		while(flag >= a[i] && i<j) i++;     //first time 'i' = 'j',this line and the last one make it come ture that put the 'flag' to the right position by use 'j--' to find the number                                                      that less than the 'flag' and 'i--' to find the bigger one then swap  with each other. While 'i' = 'j' ,it means this is the position of the 						 	'flag'     
		//printf("%3d j=%2d",i,j);//printall();
		if(i<j)  swap(&a[i],&a[j]);
		//printall();
	}
	a[left] = a[i];  //the next quick(quick(left,i-1);) will 'flag = a[left]'
	a[i] = flag;     //the flag number is the middle number of the array but before this sentence the flag is at the first position of the array so make it right
	quick(left,i-1);
	quick(i+1,right);
}
  

void merging(int *list1,int list1_size,int *list2,int list2_size)  
{  
    int i,j,k,m;  
    i = j = k = 0;  
      
    int temp[len];  
      
    while(i<list1_size&&j<list2_size)  
    {  
        if(list1[i] < list2[j])  
        {  
            temp[k++] = list1[i++];  
        }  
        else   
        {  
            temp[k++] = list2[j++];  
        }  
    }  
    //如果有剩下的，那么说明就是它是比前面的数组都大的，直接加入就可以了  
    while(i<list1_size)  
    {  
        temp[k++] = list1[i++];  
    }  
    while(j<list2_size)  
    {  
        temp[k++] =  list2[j++];  
    }  
      
    for(m=0; m<(list1_size + list2_size);m++)  
    {  
        list1[m] = temp[m];  
    }  
}  
void MergeSort(int k[],int n)  
{  
      
    if(n>1)  
    {  
        int *list1 = k;         //定义一个指针变量，指向数组k的地址  
        int list1_size = n/2;   //数组的长度分为本来数组长度的一半  
        int *list2 = k +n/2;    //定义另外一个指针变量，指向数组k+n/2的地址  
        int list2_size = n - list1_size;//长度为刚才总的减去刚才分去那一半  
          
        MergeSort(list1,list1_size);    //调用数组本身，相当与递归，  
        MergeSort(list2,list2_size);    //调用数组本身，相当与递归  
        merging(list1,list1_size,list2,list2_size);  
    }  
      
      
      
}  






























