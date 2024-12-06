#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =2*1e5+13;
typedef long long ll;
int n;
int a[N];

int comp(const void* a,const void*b){
    return (*(int*)a)-(*(int*)b);
}


int main (){

	
	scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    
    //qsort(a,n,sizeof(a[0]),compare);
    qsort(a,n,sizeof(a[0]),comp);
    
    if(a[n-1]-a[n-2]>a[1]-a[0]){//尾大
        cout<<a[n-2]-a[0];
    }else cout<<a[n-1]-a[1];
	
	return 0;
}
