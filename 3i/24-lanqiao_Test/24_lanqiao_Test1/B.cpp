#include<iostream>	//算法注释：	，心得：	，题目网址：https://ac.nowcoder.com/acm/contest/95217/B
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e5+10;



int main (){
	int cnt=5,i=1;
    while(i<10000)
        i |= (1<<(cnt++));
	cout<<cnt<<endl;
    cout<<(1<<14);
	return 0;
}



