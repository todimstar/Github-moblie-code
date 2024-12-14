#include<iostream>	//算法注释：细节模拟	，心得：别太暴力	，题目网址：https://codeforces.com/contest/2050/my
#include<stdlib.h>
#include<string>
#include<algorithm>

using namespace std;

const int N =1e5+13;
typedef long long ll;
int T;

int main (){

	
	cin>>T;
	while(T--){
        string s;
		cin>>s;
        int len = s.size(),sum=0;
        int i2=0,i3=0;
        for(int i=0;i<len;i++){
            sum+=s[i]-'0';
            if(s[i]-'0'==2){
                i2++;
            }else if(s[i]-'0'==3){
                i3++;
            }
        }
        int cha=9-sum%9;//正向上差多少
        if(cha==9){
            cout<<"YES"<<endl;
            continue;
        }if(cha&1)cha+=9;
        cha-=min(i3,cha/6)*6;
        if(cha/2<=i2){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
	}
	
	return 0;
}
