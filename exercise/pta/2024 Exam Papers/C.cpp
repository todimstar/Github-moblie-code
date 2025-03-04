#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e9+10;
typedef long long ll;
int T,n;

int main (){

	int a,b;
    cin>>a>>b;
    if(a==0){//红灯
        if(!b){//无人才需输出，有人，无需提醒
            cout<<"biii"<<endl;
        }else{
            cout<<"-"<<endl;
        }
        cout<<"stop"<<endl;
    }else if(a==1){//绿灯
        if(!b){//无人才需输出，有人，无需提醒
            cout<<"dudu"<<endl;
        }else{
            cout<<"-"<<endl;
        }
        cout<<"move"<<endl;
    }else{//黄灯
        cout<<"-"<<endl;
        cout<<"stop"<<endl;
    }
	
	return 0;
}
