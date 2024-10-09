#include<iostream>
#include<stdlib.h>

using namespace std;



void feibo(int x){
	int n,a,fn,f,ff;	
	int tf,tff;
	//x>=n>=2
	//x>=a>=2
	printf("2 %d\n",x);
	for(a=x-1;a>=2;a--){
		f=1;ff=a;	//f是n-2位继承，ff是n-1位
		tf=f;tff=ff;
		for(n=3;n<x;n++){
			fn=tf+tff;
			if(fn==x){
				printf("%d %d\n",n,a);
			}
			tf=tff;tff=fn;	//内部继承，一个变量就要多继承一次，好有劣势
		}
		
	}
}


int main (){
	int n;
	int a[100001];
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	for(int i=0;i<n;i++)feibo(a[i]);
	
	return 0;
}
