#include<iostream>	//算法注释：比大小	，心得：看破	，题目网址：https://codeforces.com/contest/2057/problem/A
#include<algorithm>
#include<unordered_map>

using namespace std;

const int N =1e5+13;
typedef long long ll;
int T,n,k;
int a[N];

int main (){

	
	cin>>T;
	while(T--){
        unordered_map<int,int> mp;

		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            mp[a[i]]++;
        }
        

	}
	
	return 0;
}
