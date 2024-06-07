#include<stdio.h>

int main (){
	
	int n,i=1,ii,flag=1,r=0;
	int j,k,q=1;
	char c;
	scanf("%d %c",&n,&c);
	if(n==1){printf("%c",c);return 0;}
	do{
		if(n-q>=0){
			i+=2;r++;
			q+=i*2;
		}else flag=0;	
	}while(flag); r--;i-=2;
	for(ii=0;ii<r;ii++){
		for(j=r;j>r-ii;j--)printf(" ");
		for(k=0;k<i-ii*2;k++)printf("%c",c);
		printf("\n");
	}for(j=0;j<r;j++)printf(" ");
	printf("%c\n",c);
	for(ii=r-1;ii>=0;ii--){
		for(j=0;j<ii;j++)printf(" ");
		for(k=0;k<i-ii*2;k++)printf("%c",c);
		printf("\n");
	}if(n-(q-=(i+2)*2))printf("%d",n-q);
	return 0;
}
