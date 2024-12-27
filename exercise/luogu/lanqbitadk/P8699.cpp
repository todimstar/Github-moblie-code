#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

const int mod = 123456;
int dp[513][513];//dp[i][j]表示有i个数其中j单调排列的排列方式数

int main() {
    int n,k;
    cin >> n>>k;
    dp[1][0]=1;
    for(int i=2;i<n;i++){
        dp[i][0]=2;
        for(int j=0;j<=i;j++){
            dp[i+1][j]+=dp[i][j]*(j+1)%mod;//因为每个之前的方案都有j+1个位置可以插入所以是乘法
            dp[i+1][j+1]+=dp[i][j]*(2)%mod;
            dp[i+1][j+2]+=dp[i][j]*(i-j-2)%mod;
        }
    }
    cout<<dp[n][k-1]%mod;
    
    return 0;
}
