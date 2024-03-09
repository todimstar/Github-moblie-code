#include<iostream>

using namespace std;
int a[1000000];//={0,1,2,3,5,7};

bool pdd(int a){
	int t=0;
	while(a){
		t+=a%10;
		a/=10;
	}if(t==23)return 1;
	else return 0;
}

int main (){
	int i,j,len=-1,sum=0,flag;
	for(i=9;i<=1000000;i+=2){
		flag=1;
		for(j=3;j<(i/2)+1;j++){
			if(i%j==0){
				flag=0;break;
			}
		}if(flag)a[++len]=i;
	}
	for(i=0;i<=len;i++){
		if(pdd(a[i]))sum++;
	}printf("%d",sum);//5503
	return 0;
}
