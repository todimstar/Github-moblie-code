#include<stdio.h>
int main (){
    long long n,i,j,t,temp;
    long long a[1000001];
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
        j=n;
        while(j--){
            for(t=0;t<j;t++){
                if(a[t]>a[t+1]){
                    temp=a[t];
                    a[t]=a[t+1];
                    a[t+1]=temp;
                }
            }
        }
        lq+=a[0]+a[1];
        a[1]+=a[0];
        a[0]=999996;
         
         
    }
    printf("%lld",lq);
     
     
    return 0;
}
