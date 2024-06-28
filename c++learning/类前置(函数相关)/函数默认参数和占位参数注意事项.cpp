#include<iostream>

using namespace std;

void fun1(int a,double){// 占位参数 :只写数据类型，往后都必须为占位参数，调用函数必须传入占位参数，但目前占位参数拿不到用不到 
	cout<<a<<endl;
}

void  fun2(int b,int c=10){//  默认参数基础.:可传可不传，但会限制函数重载， 
	cout<<b+c<<endl;
}

void fun3(int a,int b=9,int c=0, int d=5){//  默认参数注意事项1.从有默认参数开始 往后位置都得是默认参数 
	cout<<a+b+c+d<<endl;
}//  如果声明有默认值，函数实现就不能有默认参数，即默认参数不能重复定义 
void fun4(int a=20,int b=10) ;
void fun4(int a,int b){
	cout<<a+b<<endl;
}

int main(){
	
	fun4();
	
	return 0;
}
