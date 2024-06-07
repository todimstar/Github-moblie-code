#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void *a,const void*b){
	return *(int*)a-*(int*)b;
}
int main (){
	int n,i;
	scanf("%d",&n);
	int g[n],j[n];
	memset(g,0,sizeof(g));
	memset(j,0,sizeof(j));
	for(i=0;i<n;i++){
		scanf("%d",&g[i]);
		getchar();
	}
	for(i=0;i<n;i++){
		scanf("%d",&j[i]);
		getchar();
	}qsort(g,n,sizeof(g[0]),compare);
	qsort(j,n,sizeof(j[0]),compare);
	for(i=0;i<n;i++){
		if(!(j[i]>=g[i]))break;
	}printf("%d",i);
	return 0;
} 
