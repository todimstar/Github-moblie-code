#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char a[100001];
int erfen(int len);

int main (){
	int len;
	scanf("%s",a);
	len=strlen(a);
	printf("%d",erfen(len));
	return 0;
}
int erfen(int len){
	int l=0,r=len,d,cot=0;
	int askm[256],i,ll,rr;
	
	while(l<r){
		memset(askm,0,sizeof(askm));
		askm[a[d]]=1;
		d=(l+r+1)/2;ll=0;rr=0;
		for(i=0;i<d;i++){
			if(askm[a[i]]!=1){
				askm[a[i]]++;
				ll++;
			}
		}for(i=len;i>=d;i--){
			if(askm[a[i]]!=1){
				askm[a[i]]++;
				rr++;
			}
		}
		if(ll==rr)cot++;
		else if(ll<rr){l=d-1;}
		else if(ll<rr){r=d+1;}
	}
	return cot;
}
