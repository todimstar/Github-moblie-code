#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e5+10;




int main (){
	int T,n;
	int a[100001];
	
	cin>>T;
	while(T--){

		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		
		//qsort(a,n,sizeof(a[0]),compare);
		quick_sort(a,0,n-1);
		
		for(int i=0;i<n;i++)printf("%d ",a[i]);

	}
	
	return 0;
}
