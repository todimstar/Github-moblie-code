
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
    for(i=1;i<=max;i++){//�������ڼ��ж� 
        for(j=1;j<11;j++){//ÿ�ӵ�10λ��Ա 
            for(k=1;k<=n;k++){//ÿ��У������ 
                if(i<=m[k]){//��������У��Ԥ�ƶ����ܵ�����ж������� 
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
