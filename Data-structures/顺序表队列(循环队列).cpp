#include<iostream>

using namespace std;

/*顺序表实现队列------用结构包含数组和头尾指针------
实现循环队列：
法一：结构中再加入Size变量以标记当前队列中元素数量以区分空队列和满队列
法二：结构中加入tag变量以标识上一次操作为插入还是删除，以判断两指针相遇时是空队列还是满队列
法三：数组中人为控制只使用n-1个元素空间，当(Rear+1)%MaxSize==Front时一眼丁真为满队列 */

//resolution 3
#define MaxbackSize 3      //这里Max其实不是Max是能用的n+1,因为用了n-1法3 
typedef struct{
	int* Data;
	int Front;
	int Rear;
}List,*L;

void initList(L& a){
	a=new List; //实例化一个List; 
	a->Data=new int[MaxbackSize];
	a->Front=0;
	a->Rear=0;
}

bool PushList(L& a,int data){
	if((a->Rear+1)%MaxbackSize==a->Front)return false; //关键判断(Rear+1)%MaxbackSize==front;以留 
	a->Data[a->Rear++]=data;
	return true;
}

bool PopList(L&a,int& data){ //注意data的& 
	if(a->Front==a->Rear)return false;
	data=a->Data[a->Front++];    //区别于栈的地方，队头退出 
	return true;
}

int main () {
	//List a;
	L list;//=&a;   //复习: 如果a是指针*a是解引用a指向的内存的数据,如果a是数据类型,那么a*是a类型的指针类型; 
	int top=0;
	initList(list);
	cout<<PopList(list,top)<<"top="<<top;
	cout<<'\n'<<PushList(list,1)<<PushList(list,2)<<PushList(list,3)<<PushList(list,4)<<'\n';
	cout<<PopList(list,top)<<"top="<<top;
	cout<<PopList(list,top)<<"top="<<top;
	cout<<PopList(list,top)<<"top="<<top;
	
	delete[] list->Data; //记得删除 
	delete list;
	return 0;
}
