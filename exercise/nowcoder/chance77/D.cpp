#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =2000+10;
typedef long long ll;
int n,q;
int qq[N];

struct mo{
    int ai;
    int i;
};
mo m[N];

int compare(const void* a,const void* b){//正序
    return (((mo*)a->ai)-((mo*)b->ai));
}

int solve(int i){
    qsort(m,sizeof(m[i]),sizeof(m),compare);
    
    for(int j=n-1,k=n-2;j>=0&&k>=0;--j,--k){
        if(j!=i&&k!=i){
            qq[]
        }
    }
}

int main (){

	
	scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&m[i].ai);
        m[i].i=i+1;
    }
    cin>>q;

    for(int i=0;i<q;i++){
        cin>>qq;
        m[i].ai = qq;
        solve(i);
    }


	
	return 0;
}
