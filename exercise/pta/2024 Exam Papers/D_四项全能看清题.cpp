#include<iostream>//理解错题意了之前用cout<<sum/n;
                    //其实应该是夹在(sum/n*n)~(n*m)之间
using namespace std;
int mm[1001];
int main (){
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>mm[i];
        sum+=mm[i];
    }
    if(sum==n*m)    //n*m是最大，
        cout<<n;
    else if(n*(m-1)>sum)//小于n人*(m-1)个技能就是没人拿得全
        cout<<0;
    else
        cout<<sum-sum/n*n;//正常有人就是介于<n*(m-1)>到<n*m>之间
    
    return 0;
}