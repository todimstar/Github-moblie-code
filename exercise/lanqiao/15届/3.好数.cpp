#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

string tostring(int n){
  string result;
  while(n){
    result+='0'+n%10;
    n/=10;
  }
  reverse(result.begin(),result.end());
  return result;
}

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin>>n;
  
  int cnt=0;
  for(int tt=1;tt<=n;tt++){
    string s = to_string(tt);
    reverse(s.begin(),s.end());
    int len = s.size();
    bool flag=true;
    for(int i=0;i<len;i++){
      if(i&1){//i是奇数，则为数的偶数位
        if((s[i]-'0')&1){//非偶数
          flag = false;
          break;
        }
      }else{//i为偶数，为数的奇数
        if(!((s[i]-'0')&1)){//数为偶数
          flag = false;
          break;
        }
      }
    }
    if(flag){
      cnt++;
      cout<<tt<<endl;
    }
  }
  cout<<cnt;
  
  return 0;
}