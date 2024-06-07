#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Reverse(List L);

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Reverse( List L ){//=====只有1个结点	2个结点	空链表  会段错误
    List head=NULL,p=L,pp=NULL;
    
    while(p!=NULL){
        pp=p->Next;
        p->Next=head;
        head=p;p=pp;
    }
    return head;
}

List Read() {
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
