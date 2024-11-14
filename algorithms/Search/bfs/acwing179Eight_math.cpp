#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

const int N =2000+10;
typedef long long ll;
int T,n;
string start;
queue<string>q;
unordered_map<string,int> dp;//string>dp; //int> dp;//
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
string ds="durl";


int bfs(string start){
    string end ="12345678x";
    if(start == end)return 0;//"";//0;
    else{
        q.push(start);
        dp[start] = 0;//"";//0;
        while(!q.empty()){
            string t = q.front();
            q.pop();
            //string old = dp[t];
            int old = dp[t];
            if(t == end)return old;

            int ox,oy,oo=t.find('x');
            ox = oo/3;oy = oo%3;
            for(int i=0;i<4;i++){
                int x = ox+dx[i];
                int y = oy+dy[i];
                if(x>=0 && x<3 && y>=0 && y<3){
                    swap(t[oo],t[x*3+y]);
                    
                    if(!dp.count(t)){
                        q.push(t);//没有才进入队列维持bfs
                        //dp[t]+=ds[i];//记录路径
                        dp[t] = old+1;
                    }

                    swap(t[oo],t[x*3+y]);//恢复为了剩下的i方向遍历
                }
            }
        }
    }return -1;//"unsolvable";//-1;//
}

int main (){

	char a;
    for(int i=0;i<9;i++){
        cin>>a;
        start += a;
    }
    cout<<bfs(start);
	
	
	return 0;
}
