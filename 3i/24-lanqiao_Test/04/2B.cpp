#include<iostream>	//算法注释：栈 题目网址：https://ac.nowcoder.com/acm/contest/97419/B
#include<stdlib.h>
#include<string>
#include<stack>
#include<vector>

using namespace std;

const int N =2000+10;
typedef long long ll;
int T,n;
string s;
stack<int>stk;
vector<int>stkd;

int main (){
    cin>>n>>s;
    int len =2*n,cnt=1;
    for(int i=0;i<len;i++){
        if(s[i] == '('){
            stk.push(cnt);
            stkd.push_back(cnt++);
        }
        else if(stk.size()){
            stkd.push_back(stk.top());
            stk.pop();
        }
    }if(stk.size()){
        cout<<-1;
        return 0;
    }else {
        for(int i:stkd)cout<<i;
    }
	
	return 0;
}
