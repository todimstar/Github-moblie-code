#include<iostream>	//算法注释：枚举，心得：暴力 ，题目网址：
#include<stdlib.h>
#include<string>
#include<bitset>

using namespace std;

const int N =1e2+13;
typedef long long ll;
int T,n,minn;
int a[N],b[N];//b记得最后+1输出

bool check(int l){//傻了⊙▃⊙，检查是要从高位算的，我是低位算到的，那么就反转吧，外层范围反转好了
    int core = 10,k=1;
    while(k<=10){
        if(core<1)return false;
        if(l&1){//1
            core*=2;
        }
        else core-=k;
        l = l>>1;
        k++;
        
    }return(core == 100);
}

int main (){
    
	int l=0,r = (1<<10);//,t,k;
    for(;r>l;r--){
        if(check(r)){
            /*t = l;k=0;
            while(k<10){
                cout<<(t&1);
                t = t>>1;
                k++;
            }cout<<'\n';*/
            bitset<10> t(r);
            //cout<<r<<"--"<<endl;
            cout<<t<<endl;
            for(int i =0;i<10;i++)cout<<t[i];
            cout<<endl;
        }
        
    }

	
	return 0;
}

/*#include <stdio.h>
void dfs(int *a,int n,int sum) 
{
	int i;
	if(n>10){
		if(sum==100){
			for(i=1; i<11; i++)
				printf("%d",a[i]);
			printf("\n");
		}return ;
	}
	a[n]=0;
	dfs(a,n+1,sum-n);
	a[n]=1;
	dfs(a,n+1,sum*2);

}

int main () 
{
	int a[11];
	dfs(a,1,10);
	return 0;
}*/
