#include<stdio.h>
#include<stdlib.h>
int compare_int(const void* p1, const void* p2) 
{
	return *(int*)p2 - *(int*)p1; 
}
int main (){
    int n,m[114514]={0};
    int i,j;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d",&m[i]);
    }
    
    j=sizeof(m)/sizeof(m[0]);
    qsort(m,j,sizeof(m[0]),compare_int);
    
    
    for(i=0;i<100;i++){
        printf("%d ",m[i]);
    }
    
    return 0;
}
