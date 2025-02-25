#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<string>

using namespace std;

const int N =1e9+13;
typedef long long ll;
int T,n;
int a[100005];

int main (){
    
	
	scanf("%d",&T);
	while(T--){
        bool flag=true;

		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
		    scanf("%d",&a[i]);
            if(a[i] == 1){
                flag=false;
            }
		}
        if(!flag)printf("-1\n");
        else printf("%d\n",N);
        
	}
	
	return 0;
}
