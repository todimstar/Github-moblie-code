#include<iostream>	
#include<vector>
#include<string>

using namespace std;

const int N =1e9+10;
typedef long long ll;
int T,n;


int main (){
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> b(n,0);
    for(int i=n-2;i>=0;i--){
        b[i]+=b[i+1]+a[i+1];
    }
    ll sum=0;
    for(int i=0;i<n-1;i++){
        sum+=b[i]*a[i];
    }cout<<sum;
	return 0;
}
