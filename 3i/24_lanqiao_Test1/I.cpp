#include<iostream>	//算法注释：	，心得：	，题目网址：https://ac.nowcoder.com/acm/contest/95217/A
#include<stdlib.h>
#include<string>
#include<vector>

using namespace std;

const int N =1010;
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,1,-1};
int map[N][N],jg[N][N];

int n,m;

void dfs(int r,int c){
    int sum=0,cnt=0;
    for(int i=0;i<8;i++){
        int x = r+dx[i];
        int y = c+dy[i];
        if(x>=0 && x<n && y>=0 && y<m){
            cnt++;
            sum += map[x][y];
        }
    }sum += map[r][c];
    cnt++;
    jg[r][c] = sum/cnt;//下取整
}

int main (){
    int t;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dfs(i,j);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<jg[i][j]<<" ";
        }cout<<endl;
    }
	return 0;
}



