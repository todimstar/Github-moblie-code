#include<iostream>
#include<string>

using namespace std;

class student{
	
	public:
	int stu_number;//学号
	string name;//姓名
	
	void printstuint(){
		cout<<name<<"的学号是"<<stu_number<<endl; 
	} 
};


int main (){
	student a;
	a.stu_number=2315001;
	a.name="刘胜飞";
	a.printstuint();
	return 0;
}
