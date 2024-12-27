#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N =1e9+10;
typedef long long ll;
int T=1,n,d_;
string str;
//int a[N];


void high_pow(vector<int>& a){//jg*2
    vector<int> jg;
    int t=0,len=a.size();
    for(int i=0;i<len || t;i++){
        if(i<len)t+=a[i]*2;
        jg.push_back(t%10);
        t/=10;
    }
    while(jg.back()==0 && jg.size()>1)jg.pop_back();
    a=jg;
}


int main (){

	
	//cin>>T;
	while(T--){

		cin>>n>>str;
        //cout<<str<<endl;
        reverse(str.begin(),str.end());//倒序
        d_=str.find('.');
        str.erase(d_,1);
        //cout<<str<<endl;

        vector<int> jg;//str转型之后
        for(int i=0;i<str.size();i++){
            jg.push_back(str[i]-'0');
        }
        
        while(n--){
            //for(int i:jg)cout<<i;
            //cout<<endl;
            high_pow(jg);
        }if(jg[d_-1]>4)jg[d_]++;
        
        for(int i=jg.size()-1;i>=d_;i--)cout<<jg[i];
	}
	
	return 0;
}
