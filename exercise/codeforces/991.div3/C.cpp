#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e5+13;
typedef long long ll;
int T;

bool dfs(int _sum,int i2,int i3){
    if(_sum%9==0)return true;
    else{
        if(i2>0){
            _sum+=2;i2--;
            return dfs(_sum,i2,i3);
        }if(i3>0){
            _sum+=6;i3--;
            return dfs(_sum,i2,i3);
        }if(i2==0 && i3==0)return false;
    }
}

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
        if(sum%9==0){
            cout<<"YES"<<endl;
            continue;
        }else{
            //cout<<i2<<" "<<i3<<endl;
            if(dfs(sum%9,i2,i3)){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
        
	}
	
	return 0;
}
