#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e9+10;
typedef long long ll;
int T,n;

int main (){
    int t,n,m;
	string str,strt;
    cin>>t;
    while(t--){
        str="",strt="";
    	cin>>n>>m;
        int cnt=0;
    	for(int i=0;i<n;i++){
    		cin>>strt;
            str+=strt;
            if(str.size()<=m)cnt++;
    	}
    	cout<<cnt<<endl;
    }
	
	return 0;
}
