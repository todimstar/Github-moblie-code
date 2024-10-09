#include<stdio.h>
int main()
{
    int m=0,a=1;
    long long n,sum=0;
    scanf("%d",&n);
    while((n+1)/2!=0){
        m=n%2;
        sum+=a*m;
        n/=2;
        a=a*10;
    }

    printf("%lld\n",sum);

    return 0;
}
/*通过的数组存位法
#include<iostream>

using namespace std;
const int N = 100;
int num[N];

int main()
{
    int n,i=0;
    cin>>n;
    
    while(n){
        num[i++] = n%2;
        n/=2;
    }
    for(i--;i>=0;i--){
        cout<<num[i];
    }

    return 0;
}*/