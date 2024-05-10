#include <stdio.h>
int n,m;
int path[20] = {};

void dfs(int u,int start){
    if(u > m){
        for(int i = 1;i<=m;i++){
            printf("%d ",path[i]);
        }
        printf("\n");
        return;
    }else{
        for(int i=start;i<=n;i++){
            path[u]=i;
            dfs(u+1,i+1);//==此处开递==递完再递==递到树尽头出结果==某一世界树尽头归来实只是其上一枝叶的一递罢了==从此反复归来==直至开递处的循环结束 
            path[u]=0;
        }
    }   
}

int main(){
    scanf("%d %d",&n,&m);//几个数字n,数组多大m
    dfs(1,1);
    return 0;
}
