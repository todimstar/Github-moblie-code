/*输入格式
共一行，包含一个整数 n

输出格式
按字典序输出所有排列方案，每个方案占一行*/

#include<iostream>//经典排序型枚举 
#include<stdlib.h>

using namespace std;

#define NUMMAX 7
bool bt[NUMMAX+1]={0};
int num[NUMMAX+1],n;
void dfs(int u){
	
	if(u>n){
		for(int i=1;i<=n;i++)printf("%d ",num[i]);
		printf("\n");
		return;
	}
	else{
		for(int i=1;i<=n;i++){//bt也需要+1 
			if(!bt[i]){
				bt[i]=true;
				num[u]=i;
				dfs(u+1);
				bt[i]=false;
			}
		}
	}
	
}



int main (){
	
	scanf("%d",&n);
	//for(int i=1;i<=n;i++)num[i]=i;//小丑 
	
	//qsort(a,n,sizeof(a[0]),compare);
	dfs(1);
	
	//for(int i=0;i<n;i++)printf("%d ",a[i]);
	
	return 0;
}
