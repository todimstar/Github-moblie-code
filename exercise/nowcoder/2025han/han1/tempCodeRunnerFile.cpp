#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<unorded_map>
#include<string>

using namespace std;

const int N =1e5+13;
typedef long long ll;
int T,n;


int solve(){

}

int main (){
    int a;
	
	cin>>T;
	while(T--){
        unorded_map<int,int> mp;
        int num1=0,num2=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
            scanf("%d",&a);
            if(!num1)num1=a;
            else if(!num2)num2=a;
            else if(a!=num1&&a!=num2){//超2
                printf("No\n");
                break;
            }
            if(!(a&1)){//偶
                mp[a]++;
            }else{
                printf("No\n");
                break;
            }
            
        }
		

	}
	
	return 0;
}
