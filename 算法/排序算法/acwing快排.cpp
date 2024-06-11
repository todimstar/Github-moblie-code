#include<iostream>
#include<stdlib.h>
using namespace std;

int compare(const void* a,const void* b){
    return ((*(int*)a)-(*(int*)b));
}

void quick_sort(int* q,int l,int r){
	
	if(l>=r)return;
	
	int x=q[l+(r-l)/2],i=l-1,j=r+1; //选中间点会加快速度
	while(i<j){
		do i++;while(q[i]<x);
		do j--;while(q[j]>x);
		if(i<j)swap(q[i],q[j]);
	}
	quick_sort(q,l,j);
	quick_sort(q,j+1,r);
}

void quicksort(int* q,int l,int r){//别忘了在调用前srand((unsigned)time(NULL));
	
	if(l>=r)return;
	
	int random_number=rand()%(r-l)+l; 
	int x=q[random_number],i=l-1,j=r+1,t; //随机化位置运气好能比中间点快一半 
	while(i<j){
		do i++;while(q[i]<x);
		do j--;while(q[j]>x);
		if(i<j){t=q[i];q[i]=q[j];q[j]=t;}
	}
	quicksort(q,l,j);
	quicksort(q,j+1,r);
}


int main (){
	int n;
	int a[100001];
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	//qsort(a,n,sizeof(a[0]),compare);
	//srand((unsigned)time(NULL));
	quick_sort(a,0,n-1);
	for(int i=0;i<n;i++)printf("%d ",a[i]);
	
	return 0;
}
