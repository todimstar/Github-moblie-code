//https://ac.nowcoder.com/acm/contest/view-submission?submissionId=71238923

/*
挺屌的思路：用两个row和cul数组存了标记，终点检测这个思路屌的
起点正常dfs找路，并一路标记走过的row和cul，然后终点检测能否在有路的情况抵达标记过的row和cul
*/

#include<iostream>
#include<vector>
using namespace std;
#define int long long
#define endl '\n'
int sx,sy;
int ex,ey;
int n,m;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
vector<string>s(1001);
vector<vector<bool>>vis(1005,vector<bool>(1005));
vector<vector<bool>>vis2(1005,vector<bool>(1005));
vector<bool>row(1001),cul(1001);
int q=0;
void dfs1(int x,int y){
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>n||nx<1||ny>m||ny<1) continue;
        if(s[nx][ny]=='#') continue;
        if(vis[nx][ny]) continue;
        vis[nx][ny]=1;
        row[nx]=cul[ny]=1;
        dfs1(nx,ny);
    }
}
void dfs2(int x,int y){
    if(q) return;
    for(int i=x-1;i<=x+1;i++){
        if(i<1||i>n) continue;
        if(row[i]){
            q=1;
            return;
        }
    }
    for(int i=y-1;i<=y+1;i++){
        if(i<1||i>m) continue;
        if(cul[i]){
            q=1;
            return;
        }
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>n||nx<1||ny>m||ny<1) continue;
        if(s[nx][ny]=='#') continue;
        if(vis2[nx][ny]) continue;
        vis2[nx][ny]=1;
        dfs2(nx,ny);
    }
}

void solve(){
    //暴力肯定过不了
    //判断一下连通块，一堵住就用超能力，看看能不能连通
    //就是思维啊+模拟
    //de了很久的bug,原因竟是:op从操作里面,一直vis[i][j]=1,把原来的'.'标记了,导致错误
    //改过来以后 TLE了,因为有很多个 '#',所以需要大改,总体思路没问题的
    //就是多了一个操作,那个操作就是标记用激光清除的所有路径(其实只需要看,是不是在同行/列,或者旁边就行了)
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i],s[i]=' '+s[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='S') sx=i,sy=j;
            if(s[i][j]=='E') ex=i,ey=j;
        }
    }
    vis[sx][sy]=1;
    row[sx]=cul[sy]=1;
    dfs1(sx,sy);
    vis2[ex][ey]=1;
    dfs2(ex,ey);
    if(q) cout<<"YES";
    else cout<<"NO";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--) solve();
}