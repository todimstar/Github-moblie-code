#include<bits/stdc++.h>
const int N=310;
int h[N][N],mem[N][N];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int n,m;
int dfs(int x,int y)
{
	int &u=mem[x][y];
	if(u!=-1) return mem[x][y];
	u=1;//至少可以走当前点 
	for(int i=0;i<4;i++)
	{
		int a=x+dx[i],b=y+dy[i];
		if(a>=1&&b>=1&&a<=n&&b<=m&&h[a][b]<h[x][y])
			u=std::max(u,dfs(a,b)+1);
	}
	return u;
}
signed main()
{
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) std::cin>>h[i][j]; 
	}
	memset(mem,-1,sizeof mem);
	int res=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			res=std::max(res,dfs(i,j));
		}
	}
	std::cout<<res; 
	return 0;
}