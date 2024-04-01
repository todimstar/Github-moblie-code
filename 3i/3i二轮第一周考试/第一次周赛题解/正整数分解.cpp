#include<stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        printf("%d=",a[i]);
        for(j=2;j<=a[i];j++){
            while(a[i]%j==0){
            	printf("%d",j);
            	a[i]/=j;
            	if(a[i]!=1) printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}
