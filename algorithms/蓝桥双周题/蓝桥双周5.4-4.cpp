#include <iostream>
using namespace std;
int main()
{
  int n,m,i,j,sum=0;
  cin>>n>>m;
  char a[n][m];
  for(i=0;i<n;i++){getchar();
      for(j=0;j<m;j++)scanf("%c",&a[i][j]);
  }
  for(i=1;i<n;i++){
      for(j=1;j<m-1;j++){//j=1避头,j<m-1避尾 
          if(a[i][j]=='*'){
            if(a[i-1][j-1]=='*'&&a[i-1][j+1]=='*'){
              if(sum==0)sum=1;
                int ti=2;//一个就够 
                while((i-ti>-1&&j-ti>-1&&j+ti<m)&&a[i-ti][j-ti]=='*'&&a[i-ti][j+ti]=='*'){
                  ti++;
                  if(ti>sum)sum=ti;//最后一次会多加 
                }if(ti>2)sum--;//如果ti动过就撤回一次 
            }
          }
      }
  }printf("%d",sum);
  return 0;
}
