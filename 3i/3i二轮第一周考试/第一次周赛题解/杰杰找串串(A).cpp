#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){ 
    string s="";
    cin>>s;
    vector<int> arr(128,-1);
    int resl=0;
    for(int i=0,j=0;i<s.length();i++){ ////滑动窗口 
        j=max(j,arr[s[i]]+1);
        resl=max(resl,i-j+1);
        arr[s[i]]=i;
    }
    cout<<resl;
}
