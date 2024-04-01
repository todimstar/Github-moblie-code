#include<stdio.h>
int main (){
	int n,m,k;
    int i,j,cot=1;
    int a[101]={0};
    scanf("%d %d %d",&n,&k,&m);
    j=n;
    for(i=0;i<n;i++){
        a[i]=i;
    }
    i=k;
    while(j!=1){
        
        for(;i<n;i++){
		    if(cot==m&&a[i]!=-1){
		        a[i]=-1;
		        cot=1;j--;
		    }else if(a[i]!=-1){
		        cot++;
		    }
        }
        i=0;
        
    }
    for(i=0;i<n;i++){
        if(a[i]!=-1){
            printf("%d",a[i]);
        }
    }
    
    
	return 0;
}
