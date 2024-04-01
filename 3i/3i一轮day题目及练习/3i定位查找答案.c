#include <stdio.h>
int a[20];
int mant(int k,int c[],int len)
{
    int ht=-1;
    int l;
    for(l=0;l<=len;l++){
        if(k==c[l]){
            ht=l;
            break;
        }
    }
    return ht;
}
int main()
{
    int n,d,f;
    while (scanf("%d",&n)!=EOF){
    for(int c=0;c<n;c++){
        scanf("%d",&a[c]);
    }
    scanf("%d",&d);
    f=mant(d,a,n);
    if(f<0){
        printf("No\n");
    }else{
        printf("%d\n",f);
    }
    }
    return 0;
}
