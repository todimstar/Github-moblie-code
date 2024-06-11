#include<iostream>
#include<string>

using namespace std;

class student{
	
	public:
	int stu_number=10000001;//学号  一、且在类定义就初始化 
	string name;//姓名
	
	student()=default;
	student(string names):stu_number(1000){
		//二、初始化列表：为不同构造函数提供定制版初始化 
		name=names;
	}
	
	
	void print(){
		cout<<name<<"的学号是"<<stu_number<<endl; 
	} 
};


int main (){
	student a;
	a.stu_number=2315001;
	a.name="刘胜飞";
	a.print();
	student b(a.name);
	b.print();
	return 0;
}
