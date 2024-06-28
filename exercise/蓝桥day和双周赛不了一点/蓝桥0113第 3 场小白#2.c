#include <stdio.h>
#include <stdlib.h>
//#include<string.h>

int main()
{
  int len,i,c1=0;
  scanf("%d",&len);
  
  char a[len+1];
  scanf("%s",a);

  long long left=0,right=0;
  for(i=0;i<len;i++){
    if(a[i]=='1'){
		left+=i-c1;
		c1++; 
    }
  }c1=0;
  for(i=len-1;i>=0;i--){
    if(a[i]=='1'){
		right+=len-(i+1)-c1;//   (i+1)才算的对，数学+-问题 
		c1++;
    }
  }left=left<right?left:right;
  printf("%lld",left);
  return 0;
}
