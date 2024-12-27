#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e9+10;
typedef long long ll;
int T,n;


int solve(int u){
    bool jflag=true,jg=true;

    while(u){
        int t=u%10;
        if(jflag && !(t&1)){//奇位偶数
            jg=false;
            break;
        }else if(!jflag && (t&1)){//偶位奇数
            jg=false;
            break;
        }
        jflag=!jflag;
        u/=10;
    }
    return jg;
}

int main (){
    cin>>n;
    for(int i=1;i<=n;i++){
        if(solve(i))T++;
    }
	cout<<T;
	return 0;
}
