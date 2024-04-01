#include<stdio.h>

int main (){
	int n,i,sum;
    scanf("%d",&n);
    sum=1+n;
    for(i=2;i<n;i++){
        if(!(n%i)){
            sum+=i;
        }
    }printf("%d",sum);
    
	return 0;
}
