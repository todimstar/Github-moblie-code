#include<stdio.h>
#define N 1000010

int main()
{
	char name[N];
	scanf("%s",name);
	int k,i,sum[10]={0};
	
	for(i=0;name[i]!='\0';i++)
	{
		k=name[i]-48;
		switch(k)
		{
			case 1: sum[1]++;break;
			case 2: sum[2]++;break;
			case 3: sum[3]++;break;
			case 4: sum[4]++;break;
			case 6: sum[6]++;break;
			case 7: sum[7]++;break;
			case 8: sum[8]++;break;
			case 9: sum[9]++;break;
		}
		if(k!=5) sum[5]++;
	}
	
	for(i=1;i<=9;i++)
	{
		printf("%d ",sum[i]);
	}
	
	return 0;
}
