#include<iostream>

using namespace std;

int main (){
	int i,sum=0;
	for(i=1;i<2023;i++){
		if(2023%i==0)sum++;
	}printf("%d",sum);//5?6?
	return 0;
}
