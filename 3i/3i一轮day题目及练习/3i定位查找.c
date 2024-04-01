#include<stdio.h>
int main ()
{
	int n,m,i;
	char er[n];
	
	while(scanf("%d\n%s\n%d\n",&n,er,&m)!=EOF){
	 
	
		for (i=0;i!=n;i++){
            printf("i=%d\n",i);
            printf("er[i]=%d\n",er[i]);
			if(er[i]==m){
				printf("%d\n",i);
			}
		}
		if(i==n){
			printf("No\n");
		}
	}
	
	
	return 0;
}
