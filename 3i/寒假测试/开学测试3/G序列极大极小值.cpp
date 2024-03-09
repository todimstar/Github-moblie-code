#include<iostream>

using namespace std;

int main (){
	int n,i,max=1e9,min=0;
	cin>>n;
	int a[n+1];
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=2;i<n;i++){
		if(a[i]<a[i-1]&&a[i]<a[i+1]&&a[i]>min)min=a[i];
		if(a[i]>a[i-1]&&a[i]>a[i+1]&&a[i]<max)max=a[i];
	}cout<<min<<" "<<max;
	return 0;
}
