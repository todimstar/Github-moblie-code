#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e9+10;
typedef long long ll;
int T,n;


int find_c(int i,string s,char c){//返回检查到c之前有多少个不符的字符
    int cnt=0;
    for(;i<n;i++){
        if(s[i]==c){
            return cnt;
        }
        else if(s[i]!=c){
            cnt++;
        }
    }return -1;//返回-1表示没有找到c
}

int main (){

	
	cin>>T;
	while(T--){

        
        string s;
        const char str[]="CHICKEN";

        cin>>n>>s;

        int index=0,sum=0;
        bool flag=true;
        for(int i=0;i<n;i++){
            int t=find_c(i,s,str[index]);
            if(t==-1){//连标准字符都没有
                cout<<"NO"<<endl;
                flag=false;
                break;
            }
            else{
                sum+=t;//记录间隔，最后要验证是偶数才行
                index++;
                i+=t;//搜索的i要跳过t个不符的字符
            }
        }
        if(flag && sum%2==0){
            cout<<"YES"<<endl;
        }
        else if(flag){
            cout<<"NO"<<endl;
        }



	}
	
	return 0;
}
