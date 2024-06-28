#include<stdio.h>

int arr[9] = {0};
int book[9] = {0};
int n = 0; 
int count = 0;


int f(int arr[],int left,int right)
{
	int sum = 0;
	for(;left<=right;left++)
	{
		sum = sum*10 + arr[left];
	} 
	 return sum;
}

void dfs(int arr[],int step)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int i = 0;
	if(step==9)
	{
		int l = 0;
		int r = 0;
		for(l=0;l<7;l++)
		{
			for(r=l+1;r<8;r++)
			{
				a = f(arr,0,l);
				b = f(arr,l+1,r);
				c = f(arr,r+1,8);
				if(a*c+b==n*c)
				{
					count++;
				}
			}
		}
		
	}
	for(i=0;i<9;i++)
	{
		if(book[i]==-1)
		{
			continue;
		}
		else
		{
			arr[step] = i+1;
			book[i] = -1;
			dfs(arr,step+1);
			book[i] = 0;
		}
	 } 
}

int main ()
{
	scanf("%d",&n);
	dfs(arr,0);	
	printf("%d",count);
	return 0; 
 } 
