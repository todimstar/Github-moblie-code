#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>
#include<vector>
#include<queue>

using namespace std;

const int N =2*1e5+13;
typedef long long ll;
struct point{
    int x,y;
};

int n,t;
char map[110][110];
queue<point>qu,dpa,dpb;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

int bfs(int t){

    while(t--){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)qu.push({i,j});
        }point tt;

        while(qu.size()){
            tt = qu.front();
            qu.pop();
            int cnt=0;
            for(int i=0;i<8;i++){
                int x=tt.x+dx[i];
                int y=tt.y+dy[i];
                if(x>=0 && x<n && y>=0 && y<n && map[x][y]=='*'){
                    cnt++;
                }
            }
            //跑完一个点后统计该点细胞死活
            if(map[tt.x][tt.y] == '*' && (cnt<2 || cnt>3)){
                dpa.push(tt);
            }else if(map[tt.x][tt.y] == '^' && cnt==3){
                dpb.push(tt);
            }
            
        }
        while(dpa.size()){
            tt=dpa.front();
            dpa.pop();
            map[tt.x][tt.y]='^';
        }
        while(dpb.size()){
            tt=dpb.front();
            dpb.pop();
            map[tt.x][tt.y]='*';
        }
    }
    
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j] == '*'){
                sum++;
            }
        }
    }return sum;
}


int main (){
    cin>>n>>t;
    //map.resize(n);
    for(int i=0;i<n;i++){
        cin>>map[i];
    }
	cout<<bfs(t);
	
	return 0;
}
