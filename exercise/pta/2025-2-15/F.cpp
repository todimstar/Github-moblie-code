#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main (){
	int n0,n1,n;
	cin>>n0>>n1>>n;
	
	int n0num=0,n1num=0,cha=0,mincha=1e5+13;
	bool flag=false;
	for(int i=1;i<n;i++){//不到n給男生留一間寢室
		if(n0%i || n1%(n-i)){
			continue;
		}
		else{
			int k0=n0/i;
			int k1=n1/(n-i);
			if(k0>=2 && k1>=2){
				flag=true;
				cha=abs(k0-k1);
				if(cha<mincha){
					mincha=cha;
					n0num=i;
					n1num=n-i;
				}
			}
		}
	}
	if(flag)cout<<n0num<<" "<<n1num;
	else cout<<"No Solution";
	
	
	
	return 0;
}
