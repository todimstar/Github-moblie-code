#include<iostream>

using namespace std;

typedef struct Node{
	char elem;
	Node* next;
}*L;
typedef struct queue{
	L front;
	L rear; 
}*Queue;


bool InList(Queue& list){
	L node=new Node;//新建节点 
	if(node==NULL)return false;//唯一无法入链表队的情况? 
	 
	node->next=NULL;//先封死 
	cout<<"elem=";
	cin>>node->elem;//传入 
	
	 
	if(list->front==NULL){
		list->front=node;//首次就连头 
		list->rear=node;//挪动队尾以加入 
	}else{
		list->rear->next=node;//数据链表链接
		list->rear=node; 
	}
	return true;
}

bool DeleteNode(Queue& list,char& result){
	if(list->front==NULL)return false;//空
	result=list->front->elem;
	if(list->front==list->rear){//只剩一个咯 
		list->front=list->rear=NULL;//置空 
	}else{
		list->front=list->front->next;//正常往后跑 
	}return true;
}

void DeleteList(Queue& list){
	L temp=NULL;
	while(list->front){
		temp=list->front;
		list->front=list->front->next;
		delete temp;
	}list->rear=NULL; 
}

int main (){
	/*long long a=8100178706957568;ikun
	cout<<a<<endl<<a%20<<"坤坤好棒！！"<<"\n---------------\n";*/
	
	Queue list=new queue;
	//init
	list->front=NULL;
	list->rear=NULL;
	//InList
	int i=5;
	while(i--)InList(list);
	//DeletNode
	char a='0';
	while(DeleteNode(list,a))cout<<a;
	
	DeleteList(list);
	return 0;
}
