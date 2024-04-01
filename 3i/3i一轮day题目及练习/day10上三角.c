#include<stdio.h>
int main (){
    int n,i,j,jg=0;
    int a[11][11]={0};
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++){
            if(a[j][i]!=0){
                jg+=1;
            }
        }
    }
    if(jg==n){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    
    
    return 0;
}
