#include<iostream>	
#include<stdlib.h>
#include<string>
#include<vector>

using namespace std;

const int N =1010;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool dp[N][N];

int n,m,k,cnt;

void dfs(int r,int c,int t){
    if(t >= k)return;
    else{
        for(int i=0;i<4;i++){
            int x = r+dx[i];
            int y = c+dy[i];
            if(x>0 && x<=n && y>0 && y<=m){
                if(!dp[x][y]){
                    dp[x][y]=true;
                    cnt++;
                }
                dfs(x,y,++t);
                t--;
            }
        }
    }
}

int main (){
    int t;
    cin>>n>>m>>t;

    int map[11][2];
    for(int i=0;i<t;i++){
        int r,c;
        cin>>r>>c;
        map[i][0] = r;
        map[i][1] = c;
        dp[r][c]=true;
        cnt++;
        
    }cin>>k;

    for(int i=0;i<t;i++){
        dfs(map[i][0],map[i][1],0);
    }
    cout<<cnt;
	return 0;
}



