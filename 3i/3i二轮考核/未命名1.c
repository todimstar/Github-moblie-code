#include<stdio.h>
#include<stdlib.h>

int visited[100][100]={0};//0为没走过
int a[100][100]={0};
//=======上,下,左,右
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int cost[50]={0};

int compare(const void* a,const void* b){
    return *(int*)b-*(int*)a;
}

void dfs(int x,int y,int n,int m){
    visited[x][y]=1;
    if(x==n &&y==m){
        int cot=0,cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==-1){
                    cot++;
                }
            }
        }cost[cnt++]=cot;
    }
    for(int k=0;k<4;k++){
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(nx>0 && nx<=n && ny>0 && ny<=m && visited[nx][ny]==0 && a[nx][ny]==0){
            dfs(nx,ny,n,m);
            visited[nx][ny]=0;
        }
    }
}

int main (){
    int m,n,i,j;
    
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    dfs(1,1,n,m);
    qsort(cost,50,sizeof(int),compare);
    printf("%d",cost[0]);
    
    return 0;
}
