#include<iostream>//03-16 15:32--18:08 三小时，暴力失败，不会用差分记录区间。一小时自调试二分，其实这题不能二分
using namespace std;//重点是会问Ai了，看不懂就直说，直到他解释清楚

bool check(int k,string s){
    int len=s.size();
    for(int i=0;i<=len-k;i++){
        if(s[i]=='0'){
            s[i]='1';
            for(int j=1;j<k;j++){
                if(s[i+j]=='0')s[i+j]='1';
                else s[i+j]='0';
            }
        }
    }
    for(int i=len-k;i<len;i++){
        if(s[i]=='0')return false;
    }return true;
}

int main(){

    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        
        for(int k=n;k>0;k--){
            if(check(k,s)){
                cout<<k<<endl;
                break;
            }
        }
    }
    return 0;
}