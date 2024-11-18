#include<iostream>	//算法注释：贪心，心得：读题 ，题目网址：https://course.educg.net/acm/contest_submit.jsp?problemID=9130&contestID=73
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e2+13;
typedef long long ll;
int T,n,minn;
ll a[N],b[N];//b记得最后+1输出

int solve(){
    for(int i=1;i<n;i++){
        if(a[i-1] < a[i]){
            b[i] = b[i-1]+1;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(a[i] > a[i+1]){
            b[i] = max((b[i+1]+1),b[i]);
        }
    }
    ll sum=0;
    for(int i=0;i<n;i++)sum+=b[i];
    return sum+n;
}

int main (){

	
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        if(i)getchar();
        cin>>a[i];
        //minn = min(minn,a[i]);
    }
    
    
    cout<<solve();

	
	return 0;
}
