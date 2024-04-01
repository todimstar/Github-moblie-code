// acm佬目录https://zhuanlan.zhihu.com/p/105467597 
// 快速幂理解笔记：https://zhuanlan.zhihu.com/p/95902286

#include<iostream>
using namespace std;
//#define MOD 100000007

long long pow(long long a,long long n,long long mod){
    long long ans=1;
    while(n){
        if(n&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }return ans%mod;
}
/*long long qpow(long long a,long long n,long long mod){//  不知道哪里问题卡在80% 
    if(n==0)return 1;
    else if(n%2==1)return qpow(a,n-1,mod)*a%mod;//  不管了还是递推好用
    else {
        long long t=qpow(a,n/2,mod)%mod;
        return t*t%mod;
    }
}*/

int main (){
    long long a,b,p;
    cin>>a>>b>>p;
    
    cout<<pow(a,b,p);
    return 0;
}
