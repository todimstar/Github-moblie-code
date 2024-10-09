#include<iostream>
/*不是一个个试，而是用滑动窗口从答案逆推保证走过所有组合，其实也就O(n)  https://ac.nowcoder.com/acm/contest/90072/A 发现前缀和与滑动窗口关系.md*/

using namespace std;

const int N = 5010;
long long a[N],sum,summax;

int main (){
    int n,k,l=1,r;
    
    cin>>n>>k;
    r = n-k;       //左取滑动头，右取滑动尾
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-k;i++){//计最初选择
        sum+=a[i];
    }
    for(int i=n-k+1;i<=n;i++){//滑动窗口并比较
        r=i;
        sum-=a[l];
        sum+=a[r];
        l++;
        summax=summax<sum?sum:summax;
    }
    
    if(summax>=0)cout<<summax;
    return 0;
}