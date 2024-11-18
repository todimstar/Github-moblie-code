#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e6+13;
string s,mins="ZZZ";




int main (){
    int minn = 0,u;
    cin>>s;
    
    for(int i=0,len=s.size();i<len;i++){
        string s1;
        u=i;
        for(int j=0;j<len;j++){
            s1+=s[u];
            u = (u+s[u]-'A'+1)%len;
        }
        if(s1 < mins){
            mins = s1;
            minn = i;
        }
    }cout<<minn;
        
    return 0;
}