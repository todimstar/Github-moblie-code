#include<iostream>
#include<vector>
//#include<algorithm> //reverse(str.begin(),str.end())没多大意思还用时间
//9.2不，reverse
using namespace std;

vector<int> gaojing(string& H,int b){
    vector<int> A,c;
    int len=H.size();
    
    //倒装vector里,处理字符转换数字
    for(int i=len-1;i>=0;i--)A.push_back(H[i]-'0');
    
    // for(auto i:A)cout<<i;
    // cout<<endl;
    
    //去A前导零
    while(A.size()>1 && A.back()==0)A.pop_back();
    
    //开始相乘处理
    int t=0,Alen=A.size();
    for(int i=0;i<Alen || t;i++){	// ||t又保证了乘到尽头
        if(i<Alen)t+=A[i]*b;
        c.push_back(t%10);
        t/=10;
    }
    
    //去c前导零
    while(c.size()>1 && c.back()==0)c.pop_back();
    
    //c倒转为A
    A.clear();
    for(int i=c.size()-1;i>=0;i--)A.push_back(c[i]);	//每次倒别忘了len-1, ww,QAQ
    
    return A;
    
}

int main (){
    string A;
    int b;
    cin>>A>>b;
    
    vector<int> jg = gaojing(A,b);
    
    for(auto i : jg)cout<<i;
    
    return 0;
}