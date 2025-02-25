#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>
#include<vector>

using namespace std;

const int N =1e9+10;
typedef long long ll;
int T,n;

int f(int n,int t){
    if(!(n/10))return t;//只有一位数
    else{
        int sum=1;
        while(n){
            sum*=n%10;
            n/=10;
        }return f(sum,t+1);
    }
}

int main (){

	int l,r;
    cin>>l>>r;
    int maxcnt=0;
    vector<int> maxnum;
    for(int i=l;i<=r;i++){
        int t=f(i,0);
        if(t>=maxcnt){
            maxcnt=t;//记录最大乘积
        }
    }//cout<<maxcnt<<endl;
    for(int i=l;i<=r;i++){
        int t=f(i,0);
        if(t==maxcnt){
            maxnum.push_back(i);//记录最大乘积对应的数
        }
    }

    cout<<maxcnt<<endl;
    for(int i=0;i<maxnum.size()-1;i++){
        cout<<maxnum[i]<<" ";
    }cout<<maxnum[maxnum.size()-1];
	
	return 0;
}
