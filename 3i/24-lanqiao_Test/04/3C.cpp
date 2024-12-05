#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<cstring>
#include<queue>

using namespace std;

const int N =500+13;
typedef long long ll;
struct point{
    int x,y;
};
int T,n,m;
//queue<point> q;
char map[N][N];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
bool td[N][N];

bool bfs(int sx,int sy){
    queue<point>q;
    memset(td,0,sizeof(td));
    q.push({sx,sy});
    td[sx][sy]=true;
    point t;
    while(q.size()){
        t = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int x=t.x+dx[i];
            int y=t.y+dy[i];
            if(x>=0 && x<n && y>=0 && y<m && map[x][y]!='x'){
                if(map[x][y] == 't')return true;
                else{
                    if(!td[x][y]){
                        td[x][y]=true;
                        q.push({x,y});
                    }
                }
            }
        }
    }return false;
}

int main (){

	
	cin>>T;
	while(T--){
        //memset(map,0,sizeof(map));
        int sx,sy;
		scanf("%d %d",&n,&m);
        getchar();
		for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%c",&map[i][j]);
                if(map[i][j] == 's'){
                    sx=i,sy=j;
                    //cout<<"sx="<<sx<<"sy="<<sy<<endl;
                }
            }getchar();
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("%c",map[i][j]);
            }printf("\n");
        }*/
        if(bfs(sx,sy))printf("YES\n");
        else printf("NO\n");
	}
	
	return 0;
}
