#include <stdio.h>
int n = 8;
int flag[10] = {};
int num[10];
void dg(int n,int cot){
    if(cot == n){
        for(int i = 0;i<n;i++){//感觉是算法不懂怎么搞... 
            if(i==n){
                printf("%d",num[i]);
            }else{
                printf("%d ",num[i]);
            }
        }
        printf("\n");
        return;
    }
    for(int i = 1;i<=n;i++){
        if(flag[i]==0){
            num[cot] = i;
            flag[i]=1;
            dg(n,cot+1);
            flag[i]=0;
        }    
    }
}
 
int main(void){
    dg(n,0);
}
