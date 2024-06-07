#include<iostream>

using namespace std;//  链表方式实现栈 头指针不动 尾指针入和出 

#define Stack_Max 10

typedef struct stack {
	char elem;
	stack* Next;
} Stack, *Link;

void initStack(Link &S) {
	S = NULL;
}

void Push_Stack(Link &S, const char e) { // 入栈

	Link T = new Stack;
	T->elem = e;
	T->Next = S;  // 当S=NULL时也可以正确继承赋值 
	S = T;

}

bool PopTop(Link &S, char& e) { // 弹出top元素
	if (S) {
		e = S->elem;
		Link T = S;
		S = S->Next;
		delete T;
		return true;
	} else return false;
}

void deleteStack(Link &S) {// 整链删除
	Link T = NULL;
	while (S) {
		T = S;
		S = S->Next;
		delete T;
	}
}

bool GetTop(Link &S, char& e) { //问top元素
	if (S) {
		e = S->elem;
		return true;
	} else return false;
}

int main () {

	Link S1 = NULL;
	char e[] = "0123456";
	for (int i = 0; i < 7; i++) {
		Push_Stack(S1, e[i]);
		cout << e[i];
	}
	cout << endl;
	char ee[7] = {0};
	for (int i = 0; i < 7; i++) {//  ee全是6666,因为7次循环都是GetTop而不动Top，所以都是同一Top
		GetTop(S1, ee[i]);
		cout << ee[i];
	}
	cout << endl;
	for (int i = 0; i < 7; i++) {//  e被倒过来装了，因为栈就是倒着出来的
		PopTop(S1, e[i]);
		cout << e[i];
	}
	cout << endl;
	for (int i = 0; i < 7; i++) { //  ee全是6666,因为7次循环都是GetTop而不动Top，所以都是同一Top
		cout << ee[i];
	}
	cout << endl;
	return 0;
}
