#include<iostream>

using namespace std;

int main (){
	int n,sum;
	cin>>n;
	sum=n/3;
	if(n%3==0)cout<<sum;
	else{
		n=n-sum*3;
		if(n%2==0)cout<<sum+n/2;
		else {//i=n/2;n%=2;
			cout<<sum+n/2+n%2;
		}
	}
	return 0;
}
