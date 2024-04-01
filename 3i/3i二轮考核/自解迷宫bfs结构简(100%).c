#include<stdio.h>

typedef struct{
	int x;
	int y;
}line;
int map[101][101];

line l[10000];//队

int bfs(int n,int m){
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, 1, 0, -1 };
	int ll = 0, tt = 0;
	int i;
	l[0].x = 1;
	l[0].y = 1;
	while (ll <= tt){
		line t = l[ll++];
		for (i = 0; i < 4; i++){
			int x = t.x + dx[i];
			int y = t.y + dy[i];
			if (x>0 && x <= n && y > 0 && y <= m && map[x][y] == 0){
				map[x][y] = map[t.x][t.y]+1;//666错用++卡半天; 
				l[++tt].x = x;
				l[tt].y = y;
			}
		}
	}return map[n][m];
}


int main(){
	int n, m,i,j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d",bfs(n, m));
	return 0;
}
