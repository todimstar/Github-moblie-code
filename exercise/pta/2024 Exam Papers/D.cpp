#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e9+10;
typedef long long ll;
int T,n;

int main (){

	int n,m;
    cin>>n>>m;
    int a[m];
    ll sum=0;
    for(int i=0;i<m;i++){
        cin>>a[i];
        sum+=a[i];
    }cout<<sum/n;

	
	return 0;
}
