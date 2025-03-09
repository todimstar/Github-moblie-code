#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e9+10;
typedef long long ll;
int T,n;


int main (){

	
	cin>>T;
	while(T--){
        int x,y;
        cin>>x>>y;
        if(y%2==0){
            cout<<"NO"<<endl;
        }else{
            int t=(y-1)/2;
            if(x&1){//x是奇数，只能解t为奇数的情况
                if(t&1){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }else {//x是偶数，只能解t为偶数的情况
                if(t%2==0){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }
        }
	}
	
	return 0;
}
