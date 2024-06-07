#include<stdio.h>
#include<string.h>
int main (){
    char a[101],*b="qiao ben zhong.\0",*c=NULL;
    int i,n,len,flag1,j,flag2;
    scanf("%d",&n);
    while(n--){getchar();
        scanf("%[^\n]",a);
        len=strlen(a);flag1=0;flag2=0;
        for(i=0;i<len;i++){
            if(a[i]==','&&a[i-1]=='g'&&a[i-2]=='n'&&a[i-3]=='o'){
                flag1=1;
            }if(a[i]=='.'&&a[i-1]=='g'&&a[i-2]=='n'&&a[i-3]=='o'&&flag1){
                for(j=len-2;j>0;j--){
                    if(a[j]==' '){
                        flag2++;
                    }if(flag2==3){
                        c=&a[j+1];break;
                    }
                }
            }
        }
        if(flag2==3){
            for(i=0;i<16;i++){
            	*(c+i)=*(b+i);
			}
            printf("%s\n",a);
        }else{
            printf("Skipped\n");
        }
    }
    return 0;
}
