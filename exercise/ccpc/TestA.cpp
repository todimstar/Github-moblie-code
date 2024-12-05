#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>/*结论：vector<>x;后使用x.reserve(n);加使用push_back();最快
emplace()比push_back慢一倍，离谱跟文章https://www.geeksforgeeks.org/push_back-vs-emplace_back-in-cpp-stl-vectors 中说的不一样，甚至反着
vector<>x(n); 跟 vector<>x;效率只高1ms这样，只有用reserve最快
但可能跟编译器有关，因为网站上的没到180ms这么夸张，但是无论哪边resever()都是最快的*/
using namespace std;

const int N =2000+10;
typedef long long ll;
int T,n;
int a[N];


int main (){

	
	cout<<"ACM-ICPC";
	
	
	return 0;
}
