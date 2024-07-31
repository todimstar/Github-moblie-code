#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void myPrint(int val){
	cout<<val<<endl;
}

int main(){
	
	//名为v的内容为int类型的vector容器 
	vector<int>v;
	
	//向容器中插入数据
	v.push_back(1314159);
	v.push_back(111);//尾插
	
	// 1. 通过迭代器访问 
	vector<int>::iterator itBegin=v.begin();//起始迭代器,指向容器第一个元素
	vector<int>::iterator itEnd=v.end();//结束迭代器,指向容器中最后一个元素的下一个位置
	
	while(itBegin!=itEnd){
		cout<<*itBegin<<endl;
		itBegin++;
	} 
	
	// 2.通过迭代器for遍历 
	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
		cout<<*it<<endl;
	} 
	
	// 3.利用STL的遍历算法
	for_each(v.begin(),v.end(),myPrint) ;//myPrint是回调函数，回调就是执行for_each时再调用 
	
	return 0;
}
