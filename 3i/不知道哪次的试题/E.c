#include<stdio.h>
#include<string.h>
int main (){
    char a[100001]={},keben[100001]={},teacher[100001]={};
    int lena,lenke,lente;
    int i,j,k=0,cg=0,weizhi=-1;
    while(scanf("%s",a)!='\n'){//字符串读入带空格应该可以用gets但是有溢出风险
        lena=strlen(a);//scanf()读入在缓冲区也有空格但是读入
        for(i=0;i<lena;i++){
            keben[i+k]=a[i];
        }
        k+=lena+1;
    }
    scanf("%s",teacher);
    
    lenke=strlen(keben);
    lente=strlen(teacher);
    
    for(j=0;j<lenke;j++){
        if(keben[j]==teacher[0]){
            weizhi=j+1;cg=1;
            for(i=1;i<lente;i++){
                if(cg==lente){
                    printf("%d",weizhi);
                    return 0;
                }
                if(keben[j+i]==teacher[i]){
                    cg+=1;
                }
                else{
                    cg=0;
                    weizhi=-1;
                    break;
                }
            }
        }
    }
    
    return 0;
}
