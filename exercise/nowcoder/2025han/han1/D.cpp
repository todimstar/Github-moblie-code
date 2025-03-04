#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<unordered_map>
#include<string>

using namespace std;

const int N =1e5+13;
typedef long long ll;
int T,n;


int main (){
    int a;
	
	scanf("%d",&T);
	while(T--){
        unordered_map<int,int> mp;
        int num1=0,num2=0;
        bool flag=true;
		scanf("%d",&n);
        if(n&1){
            
            for(int j=0;j<n;j++)scanf("%d",&a);
            flag=false;
            printf("No\n");
        }
        else{
            for(int i=0;i<n;i++){
                scanf("%d",&a);
                if(!num1)num1=a;
                else if(a !=num1 && !num2)num2=a;
                else if(a != num1 && a != num2){//超2
                    
                    for(int j=i+1;j<n;j++)scanf("%d",&a);
                    flag=false;
                    printf("No\n");
                    break;
                }
                mp[a]++;
                
                
            }
        }
		if(flag && mp[num1] == mp[num2])printf("Yes\n");
        if(flag && (!num1 || !num2))printf("No\n");
	}
	
	return 0;
}
