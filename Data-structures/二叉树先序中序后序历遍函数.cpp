#include<iostream>

using namespace std;

typedef struct TreeNode *BinTree;
struct TreeNode {
	int Data;
	BinTree Left, Right;
};


//
void PreOrderTraversal(BinTree BT) {
	if (BT) {
		cout << BT->Data;
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}
void InOrderTraversal(BinTree BT) {

	if (BT) {
		PreOrderTraversal(BT->Left);
		cout << BT->Data;
		PreOrderTraversal(BT->Right);
	}
}
void PostOrderTraversal(BinTree BT) {

	if (BT) {
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
		cout << BT->Data;
	}
}


//栈实现非递归历遍
 
typedef struct StackNode *Stack;
struct StackNode{
	BinTree Data;
	Stack Next;	
};

bool PushStack(Stack S,BinTree BT){
	if(BT){// Stack空只是空栈而已
		Stack NewStackNode=new (struct StackNode);
		NewStackNode->Data=BT;
		NewStackNode->Next=S;
		S=NewStackNode;
		return true;
	}
	else return false;//BinTree空就是空节点入到头了 
	
}

bool PopStack(Stack S){
	if(S){//栈还有 
		//执行推出
	 	cout<<S->Data;
	 	S=S->Next;
	 	return true;
	}
	else return false;//栈没了退到头了 
} 

void StackInOrderTraversal(BinTree BT) {
	Stack a=NULL;
	while(BT->Left){
		PushStack(a,BT);
		BT=BT->Left;
	}//找到左边界并暂弃了PushStack的返回值 
}


int main () {



	return 0;
}
