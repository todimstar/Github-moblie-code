#include<iostream>

using namespace std;

#define MAX 1000010
int n,a[MAX],d[MAX];

void dfs(int u){
    if(u>n){
        for(int i=1;i<=n;i++){
            printf("%d ",a[i]);
        }printf("\n");return;
    }else{
        for(int i=1;i<=n;i++){
            if(d[i]==0){
                d[i]=1;
                a[u]=i;
                dfs(u+1);
                d[i]=0;
            }
        }
    }
}

int main (){
	
	scanf("%d",&n);
    for(int i=1;i<=n;i++)a[i]=i;
	dfs(1);
	return 0;
}
