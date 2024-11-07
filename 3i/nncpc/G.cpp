#include<iostream>	//算法注释：字符串删除	，心得：函数和str的日常熟练度	，题目网址：https://csexam.gxu.edu.cn/team/problems/107/text
#include<stdlib.h>//java有replace("要被换的字符","换成")
#include<string>//cpp有str.find("")返回出现下标，str.erase(start,end)

using namespace std;

const int N =1e6+10;
int a[N];
int n,k;



int main (){

    string str1,str2;
	
	cin>>str1>>str2;
	
    while(str1.find(str2) != string::npos){
        str1.erase(str1.find(str2),str2.size());
    }

	cout<<str1;

	return 0;
}
