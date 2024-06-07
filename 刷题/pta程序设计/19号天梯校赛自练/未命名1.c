#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}
int main (){
	long long m,n,i;
	long long sum=0;
	scanf("%lld,%lld",&m,&n);
	long long mm[m];
	memset(mm,0,sizeof(mm));
	for(i=0;i<m;i++){
		getchar();
		scanf("%lld",&mm[i]);
	}
	qsort(mm,m,sizeof(mm[0]),compare);
	for(i=0;i<n;i++){
		sum+=mm[i];
	}printf("%lld",sum);
	return 0;
}
