#include<iostream>

using namespace std;
const int N=1010;

int ff[6][6];
int vv[N],ww[N];

int main (){
	int n,v,i,j;
	cin>>n>>v;
	
	for(i=1;i<=n;i++){
		cin>>vv[i]>>ww[i];
	}
	for(i=1;i<=n;i++){//i是第几个物品 
		for(j=0;j<=v;j++){// j是循环试探的当下所申请使用的空间 
			ff[i][j]=ff[i-1][j];//  继承 
			if(j>=vv[i]){
				ff[i][j]=max(ff[i][j],ff[i-1][j-vv[i]]+ww[i]);//  比较背包不带i本身和带i后哪个更有价值
			}
		}
	}int result=0;
	for(i=0;i<=v;i++)result=max(result,ff[n][i]);//  带了 
	cout<<result<<endl;
	return 0;
}
