#include <stdio.h>
#include <stdlib.h>

int compare(const void* a,const void *b){
  return (*(int*)a)-(*(int*)b);
  }

int main(int argc, char *argv[])
{
  int n,*a,sum,summax=0,i;
  scanf("%d",&n);
  a=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  qsort(a,n,sizeof(int),compare);
  for(i=0;i<=n-3;i++){
    sum=((a[i]+a[n-1])/a[i+1]);
    if(sum>summax){
      summax=sum;
    }
  }
  printf("%d",summax);
  return 0;
}
