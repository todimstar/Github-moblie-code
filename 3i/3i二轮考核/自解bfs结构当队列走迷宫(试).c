#include<stdio.h>

int map[100][100];
//int visited[100][100]={0};
typedef struct{
	int x;
	int y;
}line;line l[10000];

int bfs(int x,int y,int n,int m){
	//=======上,下,左,右 
	int dx[]={-1,0,1,0};
	int dy[]={0,1,0,-1};
	int ll=0,tt=0;
	l[0].x=x;
	l[0].y=y;
	while(ll<=tt){
		line t=l[ll++];
		for(int i=0;i<4;i++){
			int x=t.x+dx[i];
			int y=t.y+dy[i];
			if(x>0&&x<=n&&y>0&&y<=m&&map[x][y]==0/*&&visited[x][y]==0*/){
				map[x][y]=map[t.x][t.y]++;
				l[++tt].x=x;
				l[tt].y=y;
			}
		}
	}
	return map[n][m];
}

int main (){
	int n,m;
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&map[i][j]);
		}
	}
	printf("%d",bfs(1,1,n,m));
	return 0;
}
