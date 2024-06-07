#include<iostream>
#include<stdlib.h>

using namespace std;

int compare(const void* a,const void* b){
	
    return ((*(int*)a)-(*(int*)b));
}




int main (){
	int n,i,max=0,A=0,B=0,l=0,r;
	int a[511],b[511];
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>l){l=a[i];max=i;}
	}
	A=a[max];
	
	for(i=max-1,l=-1;i>=0;i--)b[++l]=a[i];
	for(i=n-1;i>max;i--)b[++l]=a[i];
	//完成前置数据处理
	r=l;l=0;max=0;
	while(l<=r){
		if(max%2==0){
			if(b[l]>b[r])B+=b[l++];
			else B+=b[r--];
		}
		else {
			if(b[l]>b[r])A+=b[l++];
			else A+=b[r--];
		}max++;
	} 
	
	printf("%d %d",A,B);
	
	return 0;
}
