#include<stdio.h>
int main (){
    int n,m[114511]={0};//改大即对 
    int i,j,p,t,cot=0,flag;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d",&m[i]);
    }
    p=n;flag=1;
    while(p-- && flag){
    	flag=0;
        for(j=p-1;j>=cot;j--){
            if(m[j]<m[j+1]){
            	flag=1;
                t=m[j];
                m[j]=m[j+1];
                m[j+1]=t;
            }
        }cot++;
        if(cot==101){
			break;
		}
        
    }
    for(i=0;i<100;i++){
        printf("%d ",m[i]);
    }
    
    return 0;
}
