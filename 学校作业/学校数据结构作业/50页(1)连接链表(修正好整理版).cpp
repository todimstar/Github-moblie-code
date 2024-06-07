#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

long long N = 100000001;

typedef struct a {
	long long uid;
	a* next;
} List, *L;

int initList(L &head, int n, long long uid) {
	if (n > 0) {
		L p = (L)malloc(sizeof(List));
		p->uid = uid;
		p->next=NULL; // 别把第一个的NULL忘了┭┮﹏┭┮ 
		head = p;
		//printf("当前链表创建的头地址为%x\n",head);
		cout << "当前链表创建的头地址为" << (void*)head << endl;
		L last = p;
		n--;
		while (n--) {
			L p = (L)malloc(sizeof(List));
			p->uid = ++uid;
			p->next = NULL;
			last->next = p;
			last = p;
		}
		return 1;
	} else if(n==0)head = NULL;
	else printf("没有负链表兄弟\n");
	return 0;
}
L printList(L head) {
	L hh = NULL;
	if (head != NULL) { //printf("当前链表头地址为%x\n",head);
		//cout<<"当前链表的头地址为"<<(void*)head<<endl;
		while (head != NULL) {
			cout << head->uid;
			head = head->next;
			if (head != NULL) {
				cout << " -> ";
				hh = head;
			}
		}
		printf("\n");
	} else cout << "空链表" << endl;
	return hh;
}

List* MergeList(List* La, List* Lb) { //默认无头结点
	L Temp = NULL, Head = La;
	if (La && Lb) {
		La = La->uid <= Lb->uid ? La : Lb; //保La头最小
		Temp = La; //首个必定不头插
		La = La->next;
		while (La) {
			if (Lb && La->uid > Lb->uid) { //设<为保当La前有一个时才头插,=的情况等下一个或者等Lb尾插
				//用头插?这是啥插???
				Temp->next = Lb;
				Lb = Lb->next;
				Temp->next->next = La;
			}
			Temp = La; //留种
			La = La->next;
			printList(La);
			printList(Lb);
			printList(Temp);
		}
		printf("new to Lb\n");
		if (Lb) { //even Logic error: 不能用while循环给temp赋值，因为走到这里Lb后面已全大于La末尾
			printList(Temp);
			printList(Lb);
			Temp->next = Lb; //这时Temp是La尾指针,且LaLb都存在
			Lb = Lb->next;
		}
		return Head;
	} else if (La)return La;
	else if (Lb)return Lb;
	else return La;
	/*while(La){
		if(Lb){
			Temp=La; //留前驱
			if(La->elem>=Lb->elem){
				Temp=La->Next;


				La=La->Next;
				Temp->Next=Lb;
				Temp->Next->Next=La; // 恢复La链接
				Lb=Lb->Next; //这是头插尾插???
			}
			else La=La->Next;
		}
	}while(Lb){ //如果Lb没摘完
		if(Temp){ //防止La为空链表
			Temp->Next=Lb;
			Temp=Lb;
			Lb=Lb->Next;
		}
	}*/
}


int main () {

	int a;
	L head1 = NULL, head2 = NULL, connect = NULL;
	cout << "第一个链表要多长？";
	cin >> a;
	initList(head1, a, N);
	//N+=a;  这是1-3,3-6

	cout << "那么我们第二个链表要多长？";
	cin >> a;
	initList(head2, a, N);

	printf("现在head1有：");
	printList(head1);
	printf("现在head2有：");
	printList(head2);

	head1 = MergeList(head1, head2);
	printf("处理好了：");
	printList(head1);


	return 0;
}
