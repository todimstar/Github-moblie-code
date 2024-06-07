#include <stdio.h>
#include <stdlib.h>

int compare(const void*a,const void *b){
  return *(int*)a-*(int*)b;
}

int main()
{
  int n,q,i,t;
  int a[100001];
  int l,r,d;
  scanf("%d %d",&n,&q);
  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }while(q--){
    scanf("%d %d",&l,&r);
    d=r-l+1;
    if(d<100){
      int *p=(int*)malloc(d*sizeof(int));
      for(i=l,t=0;i<=r;i++,t++){
        p[t]=a[i];
      }qsort(p,d,sizeof(int),compare);
      if(p[1]-p[0]<=365){
        printf("YES\n");
      }else printf("NO\n");
    }
    else{printf("YES\n");}
  }

  return 0;
}
