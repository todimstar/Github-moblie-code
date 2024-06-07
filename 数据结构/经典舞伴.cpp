#include<iostream>

using namespace std;

typedef struct{
	int* Data;
	int Front;
	int Rear;
	int SizeMax;
}List,*L;

void initList(L& a,int Max){
	a=new List; //实例化一个List; 
	a->Data=new int[Max+1];
	for(int i=0;i<Max;i++)a->Data[i]=i+1;
	a->SizeMax=Max;
	a->Front=0;
	a->Rear=0;
}

void PrintList(L& a){
	if((a->Rear+1)%a->SizeMax==a->Front){
		cout<<a->Data[a->Rear];
		a->Rear=0;
		return; //关键判断(Rear+1)%MaxbackSize==front;以留 
	}
	cout<<a->Data[a->Rear++];
	
}


int main () {
	//List a;
	L list1,list2;//=&a;   //复习: 如果a是指针*a是解引用a指向的内存的数据,如果a是数据类型,那么a*是a类型的指针类型; 
	int man,woman,i;
	cin>>man>>woman>>i;
	initList(list1,man);
	initList(list2,woman);
	while(i--){
		PrintList(list1);
		cout<<' ';
		PrintList(list2);
		cout<<'\n';
	}
	
	delete[] list1->Data; //记得删除 
	delete list1;
	delete[] list2->Data; //记得删除 
	delete list2;
	return 0;
}
