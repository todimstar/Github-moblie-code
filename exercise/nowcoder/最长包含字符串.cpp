#include<stdio.h>
#include<string.h>
int main (){
    char zhong[41]={0},a[11];
    int m=4,i,j,lena,zhonglen,k;
    while(m--){
        scanf("%s",a);
        lena=strlen(a);
        if(m==3){
            for(i=0;i<lena;i++){
                zhong[i]=a[i];
            }zhonglen=lena;
        }else{
            for(i=0;i<lena;i++){k=0;
                for(j=0;j<zhonglen;j++){  
                    if(a[i]==zhong[j]){
                        k=1;break;
                    }
                }if(!k){
                    zhong[++zhonglen]=a[i];
                }
            }
        }
    }printf("%d",zhonglen);
    return 0;
}
