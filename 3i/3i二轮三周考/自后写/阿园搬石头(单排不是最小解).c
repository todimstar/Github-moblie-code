#include<stdio.h>
int main (){
    long long n,i,j,t,temp;
    long long a[1000]={0};
    long long lq=0;
    scanf("%lld",&n);
    
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    if(n==1){
        printf("%lld",a[0]);
        return 0;
    }
    
    for(i=1;i<n;i++){
        
        lq+=(a[i]+a[i-1]);
        a[i]+=a[i-1];
        
        
    }
    printf("%lld",lq);
    
    
    return 0;
}
