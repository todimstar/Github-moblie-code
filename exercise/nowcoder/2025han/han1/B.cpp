#include<iostream>	//算法注释：	，心得：	，题目网址：https://ac.nowcoder.com/acm/contest/95323/B
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

const int N =1e9+13;
typedef long long ll;
int T,n;

unordered_map<int,int>mp;

int main (){
    int a,b;
    bool flag=true;
	cin>>n;

    vector<int>degree(n+1,0);
	for(int i = 0;i<n-1;i++){
	    cin>>a>>b;
		if(mp.find(a)==mp.end())mp[a]++;
        else{
            cout<<-1;
            flag=false;
        }
        degree[a]++;
        degree[b]++;
	}
    //for(int i:degree)cout<<i<<" ";
    //cout<<endl;
    if(flag){
        a=b=0;//两个端点
        for(int i = 1;i<=n;i++){
            if(degree[i]==1){
                if(!a)a = i;
                else if(!b)b = i;
                else if(i!=a&&i!=b){
                    cout<<-1;
                    flag=false;
                    break;
                }
            }
        }if(flag)cout<<a<<" "<<b;
    }
	
	return 0;
}
