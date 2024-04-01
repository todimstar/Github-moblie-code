#include<stdio.h>
#include<string.h>//使用strstr函数，结果不好用
void yi(char* c,int lenc){//移位
    char t;int i;
    t=c[0];
    for(i=1;i<=lenc-1;i++){
        c[i-1]=c[i];
    }
    c[i-1]=t;
}
int mystr(const char *b,int lenb,const char* a,int lena){//检查b是否在a内
    int i,j,jg=0,cot=1;
    for(i=0;i<lena;i++){
        if(b[0]==a[i]){
            for(j=1;j<lenb;j++){
                if(b[j]==a[i+j]){
                    cot++;
                }
                else{
                    cot=1;break;
                }
            }
            if(cot==lenb){
                jg=1;
            }
        }
    }
    return jg;
}
int main (){
    char a[3031];
    char b[3031];
    int lena,lenb,i;
    scanf("%s",a);
    scanf("%s",b);
    lena=strlen(a);
    lenb=strlen(b);
    if(lena>lenb){//通过率66.6%
        for(i=0;i<lena;i++){

            if(mystr(b,lenb,a,lena)){
                printf("true");
                return 0;
            }
            yi(a,lena);
        }
    }
    else{//通过率33.3%
        for(i=0;i<lenb;i++){//原来如此题目有说某一个是其中一个的子串

            if(mystr(a,lena,b,lenb)){
                printf("true");
                return 0;
            }
            yi(b,lenb);
        }
    }
    printf("false");//通过率0.1%
    
    return 0;
}
