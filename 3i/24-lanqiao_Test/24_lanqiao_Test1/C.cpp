#include<iostream>	//算法注释：	，心得：	，题目网址：https://ac.nowcoder.com/acm/contest/95217/A
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e5+10;



int main (){//修改原因：大于等于
    int cnt=0;
	for(int i=9;i>0;i--){
        for(int j=i;j>0;j--){
            for(int k =j;k>0;k--){
                for(int l = k;l>0;l--){
                    for(int o = l;o>0;o--){
                        if(o>0)cnt++;
                    }
                }
            }
        }
    }cout<<cnt;
	
	return 0;
}



