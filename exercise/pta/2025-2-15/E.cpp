#include<iostream>//算法注释：斐波那契	，心得：手感	，题目网址：7-5走楼梯升级版-斐波那契,几节台阶到n-几
#include<vector>
using namespace std;


int main (){
	vector<long long> a;
	a.push_back(0);
	a.push_back(0);
	a.push_back(1);
	int n,index=2;
	cin>>n;
	
	for(int i=0;i<n;i++){
		a.push_back(a[index]+a[index-1]+a[index-2]);
		index++;
	}
	cout<<a[index];
	
	
	return 0;
}
