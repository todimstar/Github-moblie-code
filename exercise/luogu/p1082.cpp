#include<iostream>	//算法注释：同余方程--拓展欧几里得定理算ax与1互余(mod b)	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e9+10;
typedef long long ll;
int T,n;

void exgcd(int a,int b,int& x,int& y){
    if(!b){
        x=1,y=0;
        return ;
    }else {
        exgcd(b,a%b,y,x);
        y-=a/b*x;
        return;
    }
}


int main (){
    int a,b,x,y;
    cin>>a>>b;
    exgcd(a,b,x,y);
    //if(f%b)cout<<"imp";
	cout<<(x%b+b)%b;
	return 0;
}
