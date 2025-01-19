#include<iostream>	//算法注释：比大小	，心得：看破	，题目网址：https://codeforces.com/contest/2057/problem/A
#include<algorithm>

using namespace std;

const int N =1e9+10;
typedef long long ll;
int T,a,b;


int main (){

	
	cin>>T;
	while(T--){

		scanf("%d %d",&a,&b);
		printf("%d\n",max(a,b)+1);

	}
	
	return 0;
}
