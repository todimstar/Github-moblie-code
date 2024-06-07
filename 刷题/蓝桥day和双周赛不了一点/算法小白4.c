#include <stdio.h>
#include <stdlib.h>

void erfen(int cot,int b){
  int l=1,r=1e9;
  long long e,aa;
  while(l+1<r){
    aa=(l+r)/2;
    e=b-cot*aa;
    if(e>0){
      l=aa;
    }else{
      r=aa;
    }
  }printf("%d\n",r);
}
  

int main(int argc, char *argv[])
{
  // 怎么数学二分呢
  int t,a,b,c;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d %d",&a,&b,&c);
    int cot=1;
    while(!((a-=c)<1))cot++;
    erfen(cot,b);
  }
  return 0;
}

/*#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 怎么数学二分呢
  int t,a,b,c;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d %d",&a,&b,&c);
    int cot=1;
    while(!((a-=c)<1))cot++;
    int f=0,bb,flag=1;
    while(flag){
     bb=b;f++;
      for(int i=0;i<cot;i++){
        bb-=f;
        if(bb<=0){
          printf("%d\n",f);
          flag=0;break;
        }
      }
    }
  }
  return 0;
}超时吧*/
