#include<stdio.h>
int main (){
	int n,t;
	int i,j;
	int a[114514]={0};//==���������ķ�Χ0~114514== 
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&t);
		a[t]+=1;
	}
	for(i=0;i<114514;i++){//==
		
		for(j=1;j<=a[i];j++){
			printf("%d ",i);
		}
		
	}
	
	
	
	return 0;
} 
