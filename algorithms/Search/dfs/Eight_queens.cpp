#include<iostream>	//算法注释：	，心得：	，题目网址：https://www.acwing.com/problem/content/847/
#include<stdlib.h>
#include<string>
#include<queue>

using namespace std;

const int N =10;
int a[N][N];
struct PII{
	int r,c;
};
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
queue<PII> q;

void bfs(int r,int c){
	int hh=0,ee=0;
	q.push({r,c});
	PII t;

	while(!q.empty()){
		t = q.front();
		q.pop();
		//cout<<t.r<<" "<<t.c<<endl;
		for(int i=0;i<4;i++){
			int x = t.r+dx[i];
			int y = t.c+dy[i];
			if(x>=0 && x<3 && y>=0 && y<3){
				a[x][y] = a[t.r][t.c]+1;
				if(x == 2 && y==2){
					cout<<a[x][y];
					return;
				}q.push({x,y});
			}
		}
	}
	cout<<-1;
	return;
}


int main (){
	string str;
	getline(cin,str);
	int k=0,r,c;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(str[k] == 'x'){
				//a[i][j] = -1;
				r=i;c=j;
				//cout<<"k="<<k;
			}
			k+=2;
		}
    }
	//cout<<r<<" "<<c<<endl;
	bfs(r,c);
	return 0;
}
