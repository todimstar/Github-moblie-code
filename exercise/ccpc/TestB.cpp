#include<bits/stdc++.h>

using namespace std;

const int N =2000+10;
typedef long long ll;
int T,n;
vector<string>a;


int main (){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
    cin>>n>>k;
    a.reserve(n);
    string t;
    a.push_back("jk");
    for(int i=1;i<n;i++){
        cin>>t;
        a.push_back(t);
    }cin>>t;
    a[0]=t;
    cout<<a[k%n];
	
	
	return 0;
}
