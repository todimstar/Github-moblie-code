#include<stdio.h>
int main (){
	
    int n,m,p,q;
    int a[20];
    
    while(scanf("%d",&n)!=EOF){ 
    for (int i=0;i!=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(p=0;p<=n;p++){
		if(m==a[p]){
			for(q=p;q!=20;q++){
				a[q]=a[q+1];
			}
		}
	}
    printf("%d\n",a);
    
    } 
    return 0;
}
