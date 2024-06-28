// acm��Ŀ¼https://zhuanlan.zhihu.com/p/105467597 
// ���������ʼǣ�https://zhuanlan.zhihu.com/p/95902286

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
/*long long qpow(long long a,long long n,long long mod){//  ��֪���������⿨��80% 
    if(n==0)return 1;
    else if(n%2==1)return qpow(a,n-1,mod)*a%mod;//  �����˻��ǵ��ƺ���
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
