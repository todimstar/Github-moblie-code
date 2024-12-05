#include<iostream>	//算法注释：奇偶? 题目网址：https://ac.nowcoder.com/acm/contest/97419/F
#include<stdlib.h>
#include<string>
#include<stack>
#include<vector>

using namespace std;

const int N =2000+10;
typedef long long ll;
int T,n;


int main (){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<4){
            if(n==1 || n==3){
                cout<<-1<<endl;
                
            }else cout<<66<<endl;
            continue;
        }else{
            string a;
            if(n&1){//奇
                for(int i=0;i<n-4;i++){
                    a+='3';
                }a+="6366";
            }else{
                for(int i=0;i<n-2;i++){
                    a+='3';
                }a+="66";
            }cout<<a<<endl;
        }
    }
	
	return 0;
}
