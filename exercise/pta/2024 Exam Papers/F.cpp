#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>
#include<vector>

using namespace std;

const int N =1e9+10;
typedef long long ll;
int T,n;

int main (){

	int n;
    cin>>n;
    vector<int> nums(n,0);
    double prices[n],sum=0;
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    int m,t;
    cin>>m;
    while(m!=0){
        cin>>t;
        nums[m-1]+=t;
        cin>>m;
    }cin>>m;//末尾0

    /*for(int i:nums){
        cout<<i<<endl;
    }*/
    //cout<<endl;
    for(int i=0;i<n;i++){
        sum+=nums[i]*prices[i];//计算种类总额
        cout<<nums[i]<<endl;
    }
    printf("%.2f",sum);
	
	return 0;
}
