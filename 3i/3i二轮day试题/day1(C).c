#include<stdio.h>
int main () {
	long long a,b,n;
    long long fn,fn1,t;
    int i;
    long long max,min,j;
	scanf("%lld %lld %lld",&a,&b,&n);
	if(n>2){
        fn=a+b;
        fn1=b+fn;
        for(i=3;i<n;i++){
            t=fn1;
            fn1+=fn;
            fn=t;
        }
    }
    else if(n==1){
        fn=a;
        fn1=b;
    }
    else {
        fn=b;
        fn1=a+b;
    }
    max=fn1;
    min=fn;
    while(min!=0){
        j=min;
        min=max%min;
        max=j;
    }
    printf("%lld",max);
    
    
	return 0;
}
