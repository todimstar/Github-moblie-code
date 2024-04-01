#include<stdio.h>
int n,sum=0;
int yong[10]={0};
int shu[10];

int qu(int l,int r){
	int jg=0,i;
	for(i=l;i<=r;i++){
		jg=jg*10+shu[i];
	}return jg;
}

void dfs(int u)
{
	int i,j,a,b,c;
    if(u>9){//从1开始的所有组合 
    	for(i=1;i<7;i++){ //a最多占7个,给b,c各留一位 
    		for(j=i+1;j<8;j++){//i,j为b,c留位置存活 
    			a=qu(1,i);
    			b=qu(i+1,j);
    			c=qu(j+1,9);
    			if(n*c==a*c+b){//能*就*不/. 
    				sum++;
    			}
    		}
    	}
    	return;
    }
    for(i=1;i<=9;i++){
    	if(!yong[i]){
    		yong[i]=1;
    		shu[u]=i;
    		dfs(u+1);
    		yong[i]=0;
    	}
    }
}

int main ()
{
	scanf("%d",&n);
    dfs(1);//从1开始找组合 
    printf("%d",sum);
	return 0; 
 } 
