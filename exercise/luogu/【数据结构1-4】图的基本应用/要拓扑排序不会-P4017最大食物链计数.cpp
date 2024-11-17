#include<iostream>	//算法注释：图的dfs、拓扑排序	，心得：	，题目网址：https://www.luogu.com.cn/problem/P4017
#include<stdlib.h>
#include<string>
#include<map>
#include<vector>

using namespace std;

const int mod =80112002;
typedef long long ll;
int n,m;
map<int,vector<int>> g;
ll sum;

int dfs(int u){
    if(g.find(u) == g.end()){
		return 1;
	}else{
		int dfssum=0;
		auto it = g[u];
		for(int i=0;i<it.size();i++){
			dfssum = (dfssum%mod + dfs(it[i])%mod)%mod;
		}return dfssum;
	}
}

void solve(){
    int a,b;
    
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[b].push_back(a);
    }
    for(auto i:g){
        cout<<i.second.size()<<" ";
    }cout<<endl;
    vector<int> it = prev(g.end())->second;
    
    for(int i=0;i<it.size();i++){
		sum = (sum%mod + dfs(it[i])%mod)%mod;
	}
}

int main (){

	
	cin>>n>>m;
	solve();
	cout<<sum;
    return 0;
}
	
