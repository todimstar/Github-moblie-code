#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

int n, m;
const int N = 110;
int a[N];

void dfs(int u,int start)
{
     
     if(u>m)
     {
         for(int i=1;i<=m;i++) cout<<a[i]<<" ";
         puts("");
         return;
     }
     if(u+n-start<m) return;
     
     for(int i=start;i<=n;i++)
     {
         a[u]=i;
         dfs(u+1,i+1);
         a[u]=0;
     }

}


int main()
{
    cin >> n >> m;
    dfs(1,1);
    return 0;
}
