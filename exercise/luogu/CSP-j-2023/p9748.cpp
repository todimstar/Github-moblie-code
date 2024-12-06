#include<iostream>	//算法注释：贪心，心得：当当前(n-1)%3==0,可以消掉第n个	，题目网址：https://www.luogu.com.cn/problem/P9748
#include<stdlib.h>
#include<string>
#include<vector>

using namespace std;

const int N =2000+10;
typedef long long ll;
int cnt,n,flag;


int main (){
    cin>>n;

    while(n){
        cnt++;
        int t=1+(n-1)/3;
        if((n-1)%3 == 0 && !flag)flag=cnt;
        n-=t;
    }
	cout<<cnt<<" "<<flag;
	return 0;
}
