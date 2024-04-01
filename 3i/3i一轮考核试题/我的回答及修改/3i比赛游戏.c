#include<stdio.h>
int main(){
    int n,m,i,a,b,sheng=0;
    
    int xx[100001]={0};
    
	scanf("%d %d",&n,&m);
	
	for(i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		xx[b]+=1;
	}
	for(i=1;i<=n;i++){//注意xx[0]也为0 
		if(xx[i]==0){//这里是败者计分制，试试胜者记分制,这得排序 
			sheng++;
		}
	}
	    printf("%d",sheng);
    return 0;
}
