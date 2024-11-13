#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =2000+10;


int main (){
    int a=2022,sum=0;
    while(a){
        a/=2;
        sum++;
    }cout<<sum;
	
	return 0;
}
