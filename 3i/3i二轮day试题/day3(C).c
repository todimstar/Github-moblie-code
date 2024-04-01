#include<stdio.h>
#include<string.h>
char zhuan(char a){
    if(a<'z' && a>'a'){
        a-=32;
    }
    return a;
}
int main (){
    char a[50000];
    char sum[100];
    int len=0,i,q=1;
    gets(a);
    len=strlen(a);
    sum[0]=a[0];
    for(i=0;i<len;i++){
        if(a[i]==' '){
            sum[q]=zhuan(a[i+1]);
            q++; 
        }
    }
    len=strlen(sum);
    for(i=0;i<len;i++){
        printf("%c",sum[i]);
    }
    
    return 0;
}
