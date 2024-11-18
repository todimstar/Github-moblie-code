#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>
#include<math.h>
#include<vector>

using namespace std;

const int mod =1e9+7;
typedef long long ll;

int k,n;
ll a[2000010];



ll solve(ll a,ll b){
    ll big=max(a,b),sml=min(a,b),jk=0,t=1;
    vector<int> bi,sm;
    for(int i=0;big;i++){
        bi.push_back(big%k);
        big/=k;
    }
    for(int i=0;sml;i++){
        sm.push_back(sml%k);
        sml/=k;
    }
    for(int i=0;i<sm.size();i++){
        bi[i] = (bi[i]+sm[i])%k;
    }
    for(int i=0;i<bi.size();i++){
        jk += bi[i]*t;
        t*=k;
    }
    return jk;
}

int main (){
    ll sum=0,tt=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        tt += a[i];
    }tt -= a[0];
    //sum = (sum + (solve(a[0],tt))%mod)%mod;
	cout<<solve(a[0],tt);
	return 0;
}
