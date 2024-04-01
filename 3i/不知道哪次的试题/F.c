#include<stdio.h>
#include<string.h>
int zhuan(char a){
    int jg=0;
    jg=a-'z';
    return jg;
}

int main (){
    int n,i,len,j,sum=0;
    char a[100011]={};
    
    scanf("%d",n);
    for(i=0;i<n;i++){
        sum=0;
        scanf("%s",a);
        len=strlen(a);
        for(j=0;j<len;j++){
            sum+=zhuan(a[j]);
        }
        printf("%d\n",sum);
    }
    return 0;
}
