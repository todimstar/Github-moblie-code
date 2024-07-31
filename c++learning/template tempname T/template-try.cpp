#include<iostream>
#include<stdlib.h>

using namespace std;

template<typename T>    //声明个模板，让编译器不要对后面的T类型报错，这是模板
void mySwap(T &a,T &b)
{
    T temp=a;
    a=b;
    b=temp;
}

int main (){
	int a,b;
	//int a[100001];
	
	scanf("%d %d",&a,&b);

    //1.自行推
    mySwap(a,b);    //编译器自行推测，根据传入猜
    printf("%d %d\n",a,b);
    //2.显示指定类型
    mySwap<int>(a,b);

	printf("%d %d\n",a,b);
	
	return 0;
}
