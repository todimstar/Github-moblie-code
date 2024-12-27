#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>//40%通过
#include<cstring>

using namespace std;

const int N =1e5+13;
typedef long long ll;
int T,n;
int t[N],d[N],l[N];
bool vis[11];
int num[N];
int dfs(int u)
{
    if(u==n){
        int time=t[num[0]]+l[num[0]],jk=0;
        for(int i=1;i<n;i++){
        	jk=num[i];
            if(time<=t[jk]+d[jk]){//如果时间小于到达时间加上等待时间
                time=max(time,t[jk])+l[jk];//竟然是这里的问题，之前直接time+=l[jk]是不准确的，因为到达时间应该是max(time,t[jk])不然飞机没到都降落了
            }else {
                return false;
            }
        }
        //for(int i=0;i<n;i++)printf("%d ",num[i]);
        return true;
    }
    else{
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                num[u]=i;
                if(dfs(u+1))return true;
                vis[i]=0;
            }
        }
    }
	return false;
}

int main (){

	
	cin>>T;
	while(T--){

		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d %d %d",&t[i],&d[i],&l[i]);
		memset(vis,0,sizeof(vis));
        memset(num,0,sizeof(num));
		if(dfs(0))printf("YES\n");
        else printf("NO\n");

	}
	
	return 0;
}