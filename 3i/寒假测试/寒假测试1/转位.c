#include<stdio.h>
#include<string.h>
char a[19];
void zhuan(char a[],int len){
    int flag=1;
    long long jg=1;
    while(flag){jg=1;
        for(int i=0;i<len;i++){
            if(a[i]=='0')continue;
            jg*=a[i]-'0';
        }printf("%lld\n",jg);
        if(jg<10)flag=0;
        else{len=0;
            while(jg){
                a[len++]=jg%10+'0';//啥波，忘转字符形式 
                jg/=10;
            }
        }
    }
}

int main (){
    
    int len;
    scanf("%s",a);
    len=strlen(a);
    zhuan(a,len);
    return 0;
}
