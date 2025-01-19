#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const int N =1e9+10;
typedef long long ll;
int T,n;
string str;
vector<int>d;
//int a[N];

void high_pow(){
    vector<int>jg;
    int t=0,len=d.size();
    for(int i=0;i<len || t;i++){
        if(i<len)t+=d[i]*2;
        jg.push_back(t%10);
        t/=10;
    }
    while(jg.size()>1 && jg.back()==0)jg.pop_back();
    d=jg;
}


int main (){
    cin>>n>>str;
    reverse(str.begin(),str.end());
    int d_=str.find('.');
    str.erase(d_,1);

    //cout<<str<<endl;
    for(int i=0;i<str.size();i++)d.push_back(str[i]-'0');//去了，这里的字符串没转义
    //for(int i:d)cout<<i;
    //    cout<<endl;
    for(int i=0;i<n;i++){
        high_pow();
        //for(int i:d)cout<<i;
        //cout<<endl;
    }
    if(d[d_-1]>4)d[d_]++;
    for(int i=d.size()-1;i>=d_;i--)cout<<d[i];
	
	return 0;
}
