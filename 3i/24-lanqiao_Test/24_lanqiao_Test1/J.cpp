#include<iostream>	//算法注释：	，心得：	，题目网址：https://ac.nowcoder.com/acm/contest/95217/A
#include<stdlib.h>
#include<string>
#include<vector>

using namespace std;

const int N =1010;
int dx[]={1,2,3,0,0,0,1,2};//9个
int dy[]={0,0,0,1,2,3,1,1};
int map[N][N];


int n,m,maxx;

void dfs(int r,int c,int sum){
    if(r == n-1 && c == m-1){
        maxx = max(sum,maxx);
        return;
    }
    for(int i=0;i<9;i++){
        int x = r+dx[i];
        int y = c+dy[i];
        if(x>=0 && x<n && y>=0 && y<m){
            sum += map[x][y];
            dfs(x,y,sum);
            sum -= map[x][y];
        }
    }
}

int main (){
    int t;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
    dfs(0,0,map[0][0]);
    cout<<maxx;
	return 0;
}



