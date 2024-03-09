#include<iostream>

using namespace std;//    构造函数：1.无返回值且不用void  2.与类相同名  3.可重载           class a{  a(){} 
//                        析造函数：1.无返回值且不用void  2.~类名       3.无参数故不可重载           ~a(){} };

//一、分类：1.按参数：   有参构造  无参构造
//        2.按类型：   普通构造  拷贝构造 

class Person{
	
public: 
	//构造函数       ps:重载多用于此 
	Person(){
		cout<<"调用了Person类无参构造函数"<<endl;
	} 
	
	Person(int a){//    小小重载一下 
		age=a;
		cout<<"Person类的有参构造函数 "<<a<<endl;
	}
	
	//  拷贝构造函数
	Person(const Person &p)//   const是防修改 但&是干嘛？ 
	{
		//  将传入的人身上的所有属性 
		age=p.age;
		cout<<"现在age="<<age<<endl;
	}
	
	//析造函数 
	~Person(){
		cout<<"调用了Person类的析构函数"<<endl;
	}
	
private:
	int age; 
};


//二、调用
void test1()
{
	//1.括号法
	Person p;//默认构造函数调用
	Person p2(10);//有参构造函数调用
	Person p3(p2);//拷贝构造函数调用 
	
	//注意事项
	//调用无参构造(即默认构造)不要加();
	Person pp();//  你说这长得像不像个函数声明捏?  所以啦，括号法的默认构造就不用()咯 
	
	//2.显示法
	
	//3.隐式转换法
	 
} 
int main (){
	
	test1(); 
	
	return 0;
}
