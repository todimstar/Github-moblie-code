// #include<iostream>	//算法注释：	，心得：	，题目网址：
// #include<stdlib.h>
// #include<string>
// #include<math.h>
// #include<vector>

// using namespace std;

// const int N =2000+10;
// typedef long long ll;

// int k;
// ll a,b;



// ll solve(){
//     ll big=max(a,b),sml=min(a,b),jk=0,t=1;
//     vector<int> bi,sm;
//     for(int i=0;big;i++){
//         bi.push_back(big%k);
//         big/=k;
//     }
//     for(int i=0;sml;i++){
//         sm.push_back(sml%k);
//         sml/=k;
//     }
//     for(int i=0;i<sm.size();i++){
//         bi[i] = (bi[i]+sm[i])%k;
//     }
//     for(int i=0;i<bi.size();i++){
//         jk += bi[i]*t;
//         t*=k;
//     }
//     return jk;
// }

// int main (){

//     cin>>k>>a>>b;

// 	cout<<solve();
	
// 	return 0;
// }

#include<iostream>
using namespace std;
int main()
{
    long long c=0;
    long long d=0;
   long long a,b,k;
    cin>>k>>a>>b;
    long long i=1;
    long long sum1=0,sum2=0;
  
    
    while(a!=0||b!=0)
    {
        c+=((a%k+b%k)%k)*i;
        i=i*k;
        a/=k;
        b/=k;
    }
   
    cout<<c;
    return 0;
    
    
    
    
}