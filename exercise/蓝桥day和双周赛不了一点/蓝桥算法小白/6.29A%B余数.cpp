#include <iostream>
using namespace std;
/*long long jdz(long long a){
  if(a<0)return -a;
  else return a;
}*/
int main()
{
  cout<<(8)%(-3)<<endl;
  int n;
  long long a,b;
  cin>>n;
  while(n--){
    cin>>a>>b;
    long long t=a%b;
    if(t>=0)cout<<t<<endl;
    else cout<<t+abs(b)<<endl;
    
    
  }
  return 0;
}
