#include<iostream>

using namespace std;
//  拷贝构造函数调用时机

class Person
{
	public:
		Person(){
			cout<<"Preson默认构造函数调用"<<endl;
		}
		~Person(){
			cout<<"Preson析造函数调用"<<endl; 
		}
		Person(int age){
			m_age=age;
			cout<<"有参构造函数调用"<<endl;
		}
		Person(const Person &p){
			m_age=p.m_age;
			cout<<"拷贝构造函数调用了"<<endl;
		}
		int m_age;//  这次为了验证与简单就放public了 
}; 
// 1.使用一个已经创建完毕的对象来初始化一个新对象
 
void test01(){
	Person p1(10);
	Person p2(p1);
	
	cout<<"p2.m_age="<<p2.m_age<<endl;
}

// 2.值传递的方式给函数参数传值

void DoWork(Person p){//  值传递进函数时便是拷贝构造了一份 
	cout<<"a"<<endl;
}

void test02(){
	
	Person p2;
	DoWork(p2);//  值传递进函数时便是拷贝构造了一份 
} 

//xxx 3.值传递方式返回局部对象 //现在貌似应该是地址传递咯？反正肯定不算值传递了 诶所以这应该不算拷贝构造函数调用时机了 

Person DoWork2(){
	Person p1(3);
	cout<<"p1地址是"<<&p1<<endl;
	return p1;// 黑马:因为离开DoWork2要释放p1,所以返回时会创一个临时的传回去 √以前是 
}//              但现在编译器优化了,减少了不必要的拷贝构造所以地址一样了,不析构那个返回的Person类对象了
//                ,,,这波啊这波是与时俱进了 

void test03(){
	Person p=DoWork2();
	cout<<"p地址是"<<&p<<endl;
	cout<<"p.m_age="<<p.m_age<<endl;
} 
int main (){
	//test01(); 
	//test02();
	test03();
	return 0;
}
