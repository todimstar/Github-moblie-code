#include<iostream>

using namespace std;

char Y[1001][1001];
int n,m;

int pdd(char f,int x,int y){
	int i=2,sum=0;
	bool flag=true;
	while(flag){
		//flag=false;
		if(x-i>=0&&x+i<m&&y-i>=0&&y+i<n){
			if(Y[x-i][y-i]==f && Y[x-i][y+i]==f &&Y[x+i][y]==f){
				sum++;i++;
			}else flag=false;
		}else flag=false;
	}return sum;
}

/*if(i-1>=0&&i+1<m&&j-1>=0&&j+1>n){
	f=a[i]
}*/
int main (){
	char f;
	int i,j,sum=0,tsum;
	cin>>n>>m;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)cin>>Y[i][j];
	}for(i=1;i<n-1;i++){
		for(j=1;j<m-1;j++){
			f=Y[i][j];
			if(Y[i-1][j-1]==f && Y[i-1][j+1]==f &&Y[i+1][j]==f){
				tsum=1;
				tsum+=pdd(f,i,j);
				if(tsum>sum)sum=tsum;
			}
		}
	}cout<<sum;
	return 0;
}
