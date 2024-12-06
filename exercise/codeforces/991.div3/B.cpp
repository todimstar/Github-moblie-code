#include<iostream>	//算法注释：	，心得：	，题目网址：
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
        int sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if(sum%n){
            printf("NO\n");
            continue;
        }
		else{
            int q=sum/n;
            for(int i=1;i<n-1;i++){
                while(a[i-1]<q){
                    a[i-1]++;
                    a[i+1]--;
                }
            }
            for(int i=n-2;i>0;i--){
                while(a[i+1]<q){
                    a[i+1]++;
                    a[i-1]--;
                }
            }bool flag=true;
            for(int i=0;i<n;i++){
                if(a[i]!=q){
                    printf("NO\n");
                    flag=false;
                    break;
                }
            }if(flag)printf("YES\n");
        }
        
	}
	
	return 0;
}
