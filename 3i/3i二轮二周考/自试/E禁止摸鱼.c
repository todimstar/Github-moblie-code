#include<stdio.h>
#include<string.h>
int main (){
    char kb[100101];
    char ts[10010];
    int lenk,lent;
    int i,j,flag,shi=0;
    
    gets(kb);
    scanf("%s",ts);
    lenk=strlen(kb);
    lent=strlen(ts);
    
    for(i=0;i<lenk;i++){
        if(kb[i]==ts[0]){
            
            flag=i;
            shi=1;//if(lent==1)
            for(j=1;j<lent;j++){
                flag+=1;
                if(ts[j]==kb[flag]){
                    shi=1;
                }
                else{
                    shi=0;
                    break;
                }
            }
            if(shi){
                printf("%d",i+1);
                return 0;
            }
        }
    }
    printf("-1");
    
    
    
    
    return 0;
}
