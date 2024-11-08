#include<iostream>	//算法注释：	，心得：	，题目网址：https://ac.nowcoder.com/acm/contest/95217/A
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e5+10;



int main (){
	int cnt=0;
    for (int i=1;i<=2020;i++)
        if (i%4 == 0 && i%6 ==0)
            cnt+=1;
    cout<<cnt;
	
	return 0;
}



