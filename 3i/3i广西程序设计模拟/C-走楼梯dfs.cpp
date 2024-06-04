#include<iostream>

using namespace std;

#define mod 1000000007
int n,a,b,c,cot=0;
int dx[3];
void dfs(int ou){
    if(ou==n){
        cot++;
		cout<<cot<<"次\n";//24.6.2硬币转换改 
		return;
    }else {
        for(int i=0;i<3;i++){
            int x=ou+dx[i];
            if(x<=n){
                dfs(x);
            }else {
            	x=ou;
            	continue;
			}
        }
    }return;
}

int main (){
	
	scanf("%d",&n);
    for(int i=0;i<3;i++)scanf("%d",&dx[i]);
 	dfs(0);
    printf("%d",cot);
	return 0;
}
