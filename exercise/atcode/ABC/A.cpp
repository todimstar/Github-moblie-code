#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e9+10;
typedef long long ll;
int T,n;

int compare(const void* a,const void* b){
    return ((*(int*)a)-(*(int*)b));
}



int main (){
    ll a,b;
    char x;
	cin>>a>>x>>b;

    cout<<a*b;
	return 0;
}
