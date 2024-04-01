#include<iostream>

using namespace std;

#define MAX 16
int map[MAX][MAX],n,m;

int dx[]={1,1,2,2};
int dy[]={2,-2,1,-1};
int cot=0;

void dfs(int ox,int oy){
    if(ox==m&&oy==n){
        cot++;return;
    }else{
        for(int i=0;i<4;i++){
            int x=ox+dx[i];
            int y=oy+dy[i];
            if(x>0&&y>0&&x<=m&&y<=n){
                dfs(x,y);
            }else {
            	x=ox;y=oy;
            	continue;
			}
        }
    }
}

int main (){
	
	scanf("%d%d",&n,&m);
	dfs(1,1);
    printf("%d",cot);
	return 0;
}
