#include<iostream>

using namespace std;

#define Stack_Max 10

typedef struct{
	char* elem;
	int stacksize;
	int top;
}Stack;

void initStack(Stack &S,int maxsize=Stack_Max){
	S.elem=new char[maxsize];  //   new用法：elem*=new elem-type; 
	S.stacksize=maxsize;
	S.top=-1;
}

void deleteStack(Stack &S){
	delete []S.elem;//  尽管对于简单数据结构类型有无[]效果一样，但是对于类对象得有[]才能调用除首地址外数组元素的析构函数 
	S.stacksize=0;
	S.top=-1; 
}

bool GetTop_Stack(Stack S,char e){
	if(S.top==-1)return false;
	e=S.elem[S.top];
	return true;
}

bool Push_Stack(Stack &S,char e){
	if(S.top==S.stacksize-1) {cout<<"拉满了"<<endl;return false;}
	else {S.elem[++S.top]=e;return true;}
}

bool Pop_Stack(Stack &S){
	if(S.top==-1){cout<<"pop到头了"<<endl;return false;}
	S.top--;return true;
}

int main (){
	
	Stack S1;// 创了个栈配套结构;
	initStack(S1); 
	char a=0;
	cout<<GetTop_Stack(S1,a)<<' is '<<a<<endl;
	
	return 0;
}
