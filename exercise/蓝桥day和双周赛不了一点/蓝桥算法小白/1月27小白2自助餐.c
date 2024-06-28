#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int mystrcmp(char a1[],char a2[]){
  int len1,len2,i;
  len1=strlen(a1);len2=strlen(a2);
  if(len1!=len2)return -1;
  else
  for(i=0;i<len1;i++){
    if(a1[i]!=a2[i]){
      return -1;
    }
  }return 0;
}

int main()
{

  int n,i,sum=0;//如果char 二维数组a[0]不为字符串那后面的"yuanxing"等初始化无效，666 
  char a[7][14]={"nb","yuanxing","zhengfangxing","changfangxing","sanjiaoxing","tuoyuanxing","liubianxing"};
  scanf("%d",&n);
  while(n--){
    scanf("%s",a[0]);
    for(i=1;i<7;i++){
      if(strcmp(a[0],a[i])==0){
        sum+=i;break;
      }
    }
  }printf("%d",sum);
  return 0;
}
