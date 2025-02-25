#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e5+13;
typedef long long ll;
int T,n;
int a[N];
//Again Test
int compare(const void* a,const void* b){
    return ((*(int*)a)-(*(int*)b));
}

int solve(){

}

int main (){

	
	cin>>T;
	while(T--){

		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		
		//qsort(a,n,sizeof(a[0]),compare);
		quick_sort(a,0,n-1);
		
		printf("%d\n",solve());

		for(int i=0;i<n;i++)printf("%d ",a[i]);

	}
	
	return 0;
}
