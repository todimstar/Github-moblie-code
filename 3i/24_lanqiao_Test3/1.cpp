#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
long long k;
const int N = 5*1e5;

struct lr{int l,r;};
string str;

int main (){
    int n,k;
    
    cin>>n>>k;
    cin>>str;
    vector<struct lr> kn;
    
    for(int i=0;i<n;i++){
        if(str[i]=='1'){
            lr t;t.l=i;
            while(str[++i]!='1');
            t.r=--i;
            kn.push_back(t);
        }
    }
    
    string c(str);
    cout<<c<<endl;
    c.insert(kn[k-1].r+1,str,kn[k].l,kn[k].r-kn[k].l+1);
    for(int i=kn[k-1].r+1;i<n;i++){
        if(i<kn[k].l || i>kn[k].r){
            c+=str[i];
        }
    }
    
    return 0;
}