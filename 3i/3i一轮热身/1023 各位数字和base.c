#include<stdio.h>
#include<string.h>
int main (){
	char n[1314]; 
	int len,i,sum;
	while(scanf("%s",n)!=EOF){ sum=0;
		len=strlen(n);
		for(i=0;i<len;i++){
			sum+=n[i]-'0';
		}
		printf("%d\n",sum);
	}
				
	return 0;
} 
