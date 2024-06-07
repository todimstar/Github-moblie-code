
#include<stdio.h>
int main (){
    int i,j,k,n,m[11];
    int duiyuan[101][11][11],max=0;
    int x=0,old=-1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&m[i]);
        if(m[i]>max)max=m[i];
    }
    for(i=1;i<=max;i++){//正在填充第几列队 
        for(j=1;j<11;j++){//每队的10位队员 
            for(k=1;k<=n;k++){//每个校轮着来 
                if(i<=m[k]){//如果这个高校的预计队伍能到填充列队数就来 
                    if(old==k){
                        x+=2;
                    }else{
                        x++;
                    }duiyuan[k][i][j]=x;
                    old=k;
                } 
            }
        }
    }
    for(i=1;i<=n;i++){
        printf("#%d\n",i);
        for(j=1;j<=m[i];j++){
            for(k=1;k<10;k++){
                printf("%d ",duiyuan[i][j][k]);
            }printf("%d\n",duiyuan[i][j][k]);
        }
    }
    return 0;
}
