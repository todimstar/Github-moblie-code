#include<iostream>
#include<stdlib.h>

using namespace std;



void bfs(int* q,int l,int r){
	
	
}


int main (){
	int n;
	int a[100001];
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	//qsort(a,n,sizeof(a[0]),compare);
	quick_sort(a,0,n-1);
	
	for(int i=0;i<n;i++)printf("%d ",a[i]);
	
	return 0;
}
