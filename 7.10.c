#include<stdio.h>
//#include<stdlib.h>
//#include"thecfunction.c"

void main()
{
	//char arr[10] = {"q","w","e","r","t","y","u","i","o","p"};
	char arr[10] = "qwertyuiop";
	int i = 0,j = 0;
	int num;
	char temp;
	printf("Original string: %s\n",arr);
	for(i=0;i<10;i++)
	{
		temp = arr[i];
		for(j=i;j<10;j++)
		{
			if(arr[j]<temp)
			{
				temp = arr[j];
				num = j;
			}
		}
		if(arr[i] != temp)
		{
			arr[num] = arr[i];
			arr[i] = temp;
		}
	}
	printf("Rearrange string: %s\n",arr);
}






