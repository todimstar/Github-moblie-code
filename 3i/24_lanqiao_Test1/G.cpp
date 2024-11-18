#include<iostream>	//算法注释：	，心得：	，题目网址：https://ac.nowcoder.com/acm/contest/95217/A
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e5+10;



int main (){
    int a,b,t;
    cin>>a>>b>>t;

    cout<<a+(b+t)/60<<endl;
    cout<<(b+t)%60;

    
	return 0;
}



