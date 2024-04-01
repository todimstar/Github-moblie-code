#include<stdio.h>

int main () {
	
	int n,m,q,x;
	int i,p,j;
	int s[100001];
	int f;
	
	scanf("%d %d %d",&n,&m,&q);
	
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
		
	}
	for(p=0;p<q;p++){
		scanf("%d",&x);
		f=n;
		for(j=0;j<n;j++){
			if(s[j]==x){
				f-=1;
			}
		}
		printf("%d\n",f);
		
	}
	
	return 0;
}
