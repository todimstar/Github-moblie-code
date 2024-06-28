#include <stdio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

// 没有头结点的单链表创建与判断 
List NoHeadinit() {
	int N;
	scanf("%d", &N);

	if (N <= 0) {
		return NULL;
	}

	List L, tail, newNode;
	L = tail = NULL;

	for (int i = 0; i < N; i++) {
		newNode = (List)malloc(sizeof(struct Node)); //模范创建单链表，单申请一个结构，再填充再连接
		scanf("%d", &(newNode->Data));
		newNode->Next = NULL;

		if (L == NULL) {
			L = tail = newNode;
		} else {
			tail->Next = newNode;
			tail = newNode;
		}
	}

	return L;
}

bool NoHeadIsNULL(List &L){
	if(L==NULL)return true;//空的
	else return false;     //非空 
}


// 有头结点的单链表创建与判断 //有无头节点区别就是不用判断是不是开头 
List HaveHeadinit(){//(List &Head) {
	int N;
	scanf("%d", &N);
	List Head=NULL;
	Head = new struct Node; //建头结点;
	Head->Data=-1;
	Head->Next = NULL;
	if (N > 0){
		List newNode = NULL,T=Head;
		while (N--) {
			newNode = new Node; 
			scanf("%d", &(newNode->Data));
			newNode->Next = NULL;

			T->Next = newNode;    //有无头节点区别就是不用判断是不是开头 
			T = newNode;

		}
	}return Head;
}

bool HaveHeadIsNULL(List &L){
	if(L->Next==NULL)return true;
	else return false;
}

void Print(List L) {
	while (L != NULL) {
		printf("%d", L->Data);
		L = L->Next;
		if (L != NULL) {
			printf(" ");
		}
	}
	printf("\n");
}

int main() {
	List a=NoHeadinit();
	Print(a);
	cout<<NoHeadIsNULL(a)<<endl;
	
	a=NULL;
	a=HaveHeadinit();
	Print(a);
	cout<<HaveHeadIsNULL(a)<<endl;
	
	return 0;
}
