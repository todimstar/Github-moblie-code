#include<iostream>	//算法注释：dfs	，心得：	，题目网址：https://ac.nowcoder.com/acm/contest/93268/C
#include<stdlib.h>
#include<string>//注意看题解，不是dfs过的

using namespace std;

const int N =1e5+10;
char map[52][52];
bool visited[52][52];
int dx[]={0,0,-1,1};//列
int dy[]={-1,1,0,0};//行
//上下左右
int n,m;//行，列
int ex,ey;//终点行，列

bool dfs(int x,int y){//行列
	if(x == ex && x == ey){
        return true;
    }else{
        for(int i =0;i<4;i++){
            int mx = x+dy[i];//行
            int my = y+dx[i];//列
            if(mx >=0 && mx<n && my>=0 && my<m && map[mx][my]=='#' && !visited[mx][my]){
                visited[mx][my]=true;
                if(dfs(mx,my))return true;
            }
        }
    }
	return false;//test return
}


int main (){

	string str;
	cin>>n>>m;
	
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<m;j++){
            map[i][j]=str[j];
        }
    }int sx,sy;
    cin>>sx>>sy>>ex>>ey;
    sx--;sy--;ex--;ey--;
    visited[sx][sy]=true;
    if(!dfs(sx,sy)){//行列
        cout<<"No";
    }else{
        cout<<"Yes";
    }
	
	return 0;
}
