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
    if(u>9){//��1��ʼ��������� 
    	for(i=1;i<7;i++){ //a���ռ7��,��b,c����һλ 
    		for(j=i+1;j<8;j++){//i,jΪb,c��λ�ô�� 
    			a=qu(1,i);
    			b=qu(i+1,j);
    			c=qu(j+1,9);
    			if(n*c==a*c+b){//��*��*��/. 
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
    dfs(1);//��1��ʼ����� 
    printf("%d",sum);
	return 0; 
 } 
