//15届蓝桥N0.9滑雪dfs，read://https_blog.csdn.net/?url=https%3A%2F%2Fblog.csdn.net%2Fm0_74183164%2Farticle%2Fdetails%2F134222318

#include<iostream>
#include<stdlib.h>

using namespace std;

int n,m;
const int N=110;
int a[N][N],mem[N][N];
int px[4]={0,0,1,-1};
int py[4]={1,-1,0,0};


int dfs(int x,int y){   //自仿题解dfs，倒着回到最开始的mem[x][y]为答案，
	if(mem[x][y])return mem[x][y];

	
	for(int i=0;i<4;i++){
		int nx=x+px[i];
		int ny=y+py[i];
		if(nx>=0&&nx<m&&ny>=0&&ny<n&&a[nx][ny]<a[x][y]){
			mem[nx][ny]=mem[x][y]+1;
			mem[x][y]+=dfs(nx,ny);
		}
	}return mem[x][y];
}
int dfs2(int x,int y){

}


int main (){
	
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
    for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d",a[i][j]);
		}cout<<endl;
	}
	int max=0,t;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			t=dfs(i,j);
			max=max<t?t:max;
            cout<<t<<" ";
		}cout<<endl;
	}
	
	printf("%d",max);
	
	return 0;
}
