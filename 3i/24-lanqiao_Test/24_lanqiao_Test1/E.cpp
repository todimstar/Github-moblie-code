#include<iostream>	//算法注释：	，心得：	，题目网址：https://ac.nowcoder.com/acm/contest/95217/A
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e5+10;



int main (){
    int cnt=0;
	string a = "LANQIAO";

    for(int i=0;i<7;i++){
        for(int j=i+1;j<7;j++){
            cnt += abs(a[i] - a[j]);
            cout<<a[i]<<" - "<<a[j]<<"=abs("<<abs(a[i] - a[j])<<endl;
        }
    }
	cout<<cnt;
	return 0;
}



