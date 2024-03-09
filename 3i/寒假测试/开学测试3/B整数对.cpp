#include<iostream>

using namespace std;

int main (){
	int l,r,sum=0;
	for(l=0;l<=100;l++){
		for(r=100;r>=0;r--){
			if(r-l>=10)sum++;
		}
	}printf("%d",sum);//4186
	return 0;
}
