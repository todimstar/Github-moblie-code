#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
long long k;
const long long mod = 20241118;

ll pow(int a,ll b){
    ll t=a,sum=1;
    
    while(b){
        if(b&1){
            sum *= t;
        }
        b=b>>1;
        t*=t;
    }
    return sum;
}

int main (){
    int n;
    int a,b;
    cin>>n;
    while(n--){
        cin>>a>>b>>k;
        int t = b/a;
        cout<<(a*pow(t,k-1))%mod<<endl;
    }
    return 0;
}