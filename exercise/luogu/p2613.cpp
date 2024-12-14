#include<iostream>	//算法注释：有理数取余--拓展欧几里得定理算bx与a互余(mod 19260817)的x，再乘a得到答案	，心得：	，题目网址：https://www.luogu.com.cn/problem/P2613
#include<stdlib.h>
#include<string>

using namespace std;

const int mod=19260817;
typedef long long ll;
int T,n;


int getint(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}while(ch>='0'&&ch<='9'){
        x=(x*10%mod+ch-'0')%mod;
		ch=getchar();
	}return x%mod*f;
}

void exgcd(int a,int b,int& x,int& y){
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b,x,y);
    int Last_x = x;
    x = y;
    y = Last_x - a / b * y;
}


int main (){
    int x,y;
    int a=getint();
    int b=getint();
    //cout<<a<<b<<endl;
    exgcd(b,mod,x,y);
    if(b%mod==0){
        cout<<"Angry!";
        return 0;
    }
	x=(x%mod+mod)%mod;
    cout<<(a*(ll)x)%mod;
	return 0;
}
