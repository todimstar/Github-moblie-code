#include<stdio.h>
#include<string.h>
int main () {
	int t,i;
	int q=0,p;
	int jg=0;
	char s[100001];
	
	scanf("%d",&t);
	
	for(i=0;i<t;i++){
		scanf("%s",s);
		q=strlen(s);
		
		for(p=0;p<q;p++){
			if(s[p]==s[p+1]){
				jg+=1;
			}
		}
	printf("%d\n",jg+q);
	jg=0;
	}
	
	
	return 0;
}
