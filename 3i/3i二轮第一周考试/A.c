#include<stdio.h>
#include<string.h>
int main (){
    char s[1000001];
    char jc[1000001];
    int len,i,j,k,f;
    int m=0,n=0;
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++){
        jc[i]=s[i];
        f=0;
        for(j=0;j<len;j++){
            if(jc[j]==s[i] && j!=i){
                for(k=0;k<len;k++){
                    jc[k]=0;
                }
                n=0;
            }
            else if(jc[j]!=s[i] && j!=i){
                f++;
            }
            if(f==len-1){
                n++;
                if(m<n){
                    m=n;
                }
            }
        }
    }
    printf("%d",m);
    
    return 0;
}
