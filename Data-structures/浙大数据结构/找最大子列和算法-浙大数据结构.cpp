#include<iostream>

using namespace std;

long long MaxSon(int* a,int n)
{	int i;
	long long Tmax=0,Smax=0;
	for(i=0;i<n;i++){
		Tmax+=a[i];
		if(Tmax>Smax)Smax=Tmax; //有贡献就带上 
		else if(Tmax<0)Tmax=0;  //跌到底扔掉 
	}return Smax;
}

int main (){
	
	int n,i;
	cin>>n;// 母列数据个数
	int a[n]; 
	for(i=0;i<n;i++)cin>>a[i];
	cout<<MaxSon(a,n);
	
	return 0;
}
