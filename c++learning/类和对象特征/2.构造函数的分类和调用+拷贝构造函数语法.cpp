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
	
	Person(int a){//    小小重载一下 // 这玩意也叫有参构造 
		age=a;
		cout<<"Person类的有参构造函数 "<<a<<endl;
	}
	
	//  拷贝构造函数
	Person(const Person &p)//   const是防修改 但&是干嘛？ // emm,毕竟是个类，传完太大了所以& 
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

    //1.括号法
void test1()
{
	
	Person p;//默认构造函数调用
	Person p2(10);//有参构造函数调用
	Person p3(p2);//拷贝构造函数调用 
	
	//注意事项
	//调用无参构造(即默认构造)不要加();
	Person pp();//  你说这长得像不像个函数声明捏?  所以啦，括号法的默认构造就不用()咯 了解 
}

    //2.显示法
void test2(){ 
	Person p;//  默认构造 
	Person p1=Person(2233);// 有参构造 
	Person p2=Person(p1);// 拷贝构造 
	
	
	Person (555);// 匿名对象 特点：执行完这行立即收回空间
	
	// attention: 不要利用拷贝构造 初始化匿名对象 
	//Person(p1); <---利用拷贝构造 初始化匿名对象 <--
				//会被认为是执行Person p1; 同时因为已有p1 报对象重定义error
}
	//3.隐式转换法
void test03(){
	Person p;
	Person p1=10; //  ==Person p1=Person(10);  有参构造
	Person p2=p1;//  拷贝构造 
	
}

int main (){
	
	test1(); 
	
	return 0;
}
