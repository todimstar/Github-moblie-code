#include<stdio.h>
int main (){
    int n,i;
    int r[1001]={0},g[1001]={0},b[1145]={0};
    int max=0,m;
    int jg[1045]={0},jgflag=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d",&r[i],&g[i],&b[i]);
    }
    m=n;
    while(m--){
        for(i=0;i<n;i++){
            if(r[i]>r[max]){
                max=i;
            }
            if(r[i]==r[max]){
                if(g[i]>g[max]){
                    max=i;
                }
                else if(g[i]==g[max]){
                    if(b[i]>b[max]){
                        max=i;
                    }
                }
                
            }
        }
        r[max]=-1;g[max]=-1;b[max]=-1;
        jg[jgflag]=max;jgflag++;
    }
    for(i=0;i<jgflag;i++){
        printf("%d",jg[i]+1);
        if(i<jgflag-1){
            printf(" ");
        }
    }
    
    
    
    
    return 0;
}
