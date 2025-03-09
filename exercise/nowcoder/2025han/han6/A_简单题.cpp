#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e9+10;
typedef long long ll;
int T,n;
int a[N];

int compare(const void* a,const void* b){
    return ((*(int*)a)-(*(int*)b));
}

int solve(){
    int cnt=1;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            cnt++;
        }
    }return cnt;
}

int main (){

	
	cin>>T;
	while(T--){

		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		
		
		printf("%d\n",solve());


	}
	
	return 0;
}
