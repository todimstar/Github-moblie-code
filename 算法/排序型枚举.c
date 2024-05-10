#include<stdio.h>
int n,m;
int path[11]={0};
int st[11]={0};
void dfs(int u){
    if(u>n){
        for(int i=1;i<=n;i++){
            printf("%d ",path[i]);
        }
        printf("\n");
    }else{
        for(int i=1;i<=n;i++){
            if(!st[i]){
                path[u]=i;
                st[i]=1;
                dfs(u+1);
                st[i]=0;
                path[u]=0;//?感觉删掉也可 
            }
        }
    }
}

int main (){
    
    scanf("%d",&n);
    
    dfs(1);
    
    return 0;
}
