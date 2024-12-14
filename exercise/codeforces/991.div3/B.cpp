#include<iostream>	//算法注释：观察题	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e5+1e5+13;
typedef long long ll;
int T,n;
int a[N];


int main (){

	
	cin>>T;
	while(T--){
        ll sum1=0,sum2=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(i&1)sum1+=a[i];
            else sum2+=a[i];
        }ll  p2=n/2;
        if(n&1 && sum1%(p2+1)==0 && sum2%(p2)==0 && sum1/(p2+1)==sum2/(p2)){//总数为奇数，且平均数相等
            printf("YES\n");
            continue;
        }else if(!(n&1) && sum1%(p2)==0 && sum2%(p2)==0 && sum1/(p2)==sum2/(p2)){//总数为偶数，且平均数相等
            printf("YES\n");
            continue;
        }else printf("NO\n");
		
        
	}
	
	return 0;
}
