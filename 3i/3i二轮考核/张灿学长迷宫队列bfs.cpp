#include<bits/stdc++.h>
using namespace std;
#include<queue>
int n,m;
int tol=0;
const int N=105;
int arr[N][N];
queue<int>xl,yl;
int x[] = {-1,0,0,1};
int y[] = {0,-1,1,0};
int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> arr[i][j];
	xl.push(1);yl.push(1);//入1队列 
    arr[1][1] = 0;
    while(xl.size()!=0)//当队空时退出 
    {
        int x_now = xl.front();//接队头 
		xl.pop();
        int y_now = yl.front();//接队头
		yl.pop();
        for(int i=0;i<4;i++){
            int x_net = x_now + x[i];//队头移动假设 
            int y_net = y_now + y[i];
            if(x_net > n || x_net < 1 || y_net > m || y_net < 1 || arr[x_net][y_net] != 0) continue;
            xl.push(x_net);//符合条件再入队 
            yl.push(y_net);
            arr[x_net][y_net] = arr[x_now][y_now] + 1;//堵路同时计数; 
        }
    }
    cout << arr[n][m];
    return 0;
}
