#include<stdio.h>
#include<string.h>
int main (){
    char a[20]={};
    int len,i,cot,j;
    int p;
    scanf("%s",a);
    len=strlen(a);
    cot=0;
    for(i=0;i<len;i++){
        if(a[i]=='.'){
            cot++;p=0;
            if(cot==1){
                j=0;
            }
            if(cot>3){
                printf("no");
                return 0;
            }
            for(;j<i;j++){
                p=10*p+a[j];
            }
            j=i+1;
            if(p>=256 || p<0){
                printf("no");
                return 0;
            }
            
        }
        else if(a[i]<48 || a[i]>57){
            printf("no");
            return 0;
        }
        
    }
    if(cot!=3){
        printf("no");
        return 0;
    }
    else{
        printf("yes");
    }
    
    
    return 0;
}
