#include<stdio.h>
int main (){
    int n,k,m;
    int r[101]={0},i;
    int flag,cot;
    scanf("%d %d %d",&n,&k,&m);
    for(i=0;i<n;i++){
        r[i]=i;
    }
    flag=n;cot=0;
    while(flag>1){
        if(flag=n){
            for(i=k;i<n;i++){
                if(r[i]>-1){
                    cot+=1;
                }
                if(cot==m){
                    r[i]=-1;cot=0;
                    flag--;
                }
            }
        }
        else{
            for(i=0;i<n;i++){
                if(r[i]>-1){
                    cot+=1;
                }
                if(cot==m){
                    r[i]=-1;cot=0;
                    flag--;
                    
                }
            }
        }
        
    }
    for(i=0;i<n;i++){
        if(r[i]>-1){
            printf("%d",i);
        }
    }
    
    
    return 0;
}
