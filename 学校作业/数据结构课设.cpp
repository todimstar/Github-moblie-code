/*1.	集合运算
题目说明：以单链表的形式表示一个集合，试编写算法实现：
（1）求出两个集合A和B的交集，即 A∩B；
（2）求出两个集合A和B的差集，即 A- B；
（3）求出两个集合A和B的并集，即 A∪B。
要求：A和B集合是由任意输入的数据构建的单链表，不是程序定死的。
*/ 

#include <iostream>
#include<string>		//5.29：打算添加系统刷新函数 //5.30直接上string 
using namespace std;

struct Node {
    string data; //5.29：int改char //5.30凌晨 char直接string方便内存管理 
    Node* next;
};

class LinkedList {
private:
    Node* head=NULL;  //5.29初审：private成员可添加以丰富拓展 

public:
    

    void insert(string value) {  //5.30凌晨修改传参string 
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    Node* getHead() {
        return head;
    }

    static LinkedList intersection(LinkedList& A, LinkedList& B) {
        LinkedList result;
        Node* a = A.getHead();
        while (a != NULL) {
            Node* b = B.getHead();
            while (b != NULL) {
                if (a->data == b->data) {
                    result.insert(a->data);
                    break;
                }
                b = b->next;
            }
            a = a->next;
        }
        return result;
    }

    static LinkedList difference(LinkedList& A, LinkedList& B) {
        LinkedList result;
        Node* a = A.getHead();
        while (a != NULL) {
            Node* b = B.getHead();
            bool found = false;
            while (b != NULL) {
                if (a->data == b->data) {
                    found = true;
                    break;
                }
                b = b->next;
            }
            if (!found) {
                result.insert(a->data);
            }
            a = a->next;
        }
        return result;
    }

    static LinkedList unionSet(LinkedList& A, LinkedList& B) {  //5.29初审：static没记错是把函数在编译时补进调用处 
        LinkedList result;
        Node* a = A.getHead();
        while (a != NULL) {
            result.insert(a->data);
            a = a->next;
        }
        Node* b = B.getHead();
        while (b != NULL) {
            Node* temp = result.getHead();
            bool found = false;
            while (temp != NULL) {
                if (temp->data == b->data) {
                    found = true;
                    break;
                }
                temp = temp->next;
            }
            if (!found) {
                result.insert(b->data);
            }
            b = b->next;
        }
        return result;
    }
};

void displayMenu() {
    cout << "1. 新增A集合成员" << endl;
    cout << "2. 新增B集合成员" << endl;
    cout << "3. 展示当前A集合成员" << endl;
    cout << "4. 展示当前B集合成员" << endl;
    cout << "5. 求出A和B交集" << endl;
    cout << "6. 求出A和B差集" << endl;
    cout << "7. 求出A和B的并集" << endl;
    cout << "8. 退出集合运算系统" << endl;
}

int main() {
    LinkedList A, B;
    int choice;
	string value;

    while (true) {
    	system("cls");  //刷新一波 
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            	system("cls");
                cout << "输入新增的A集合成员: ";
                cin >> value;
                A.insert(value);
                system("pause");
                break;

            case 2:
            	system("cls");
                cout << "输入新增的B集合成员: ";
                cin >> value;
                B.insert(value);
                system("pause");
                break;

            case 3:
            	system("cls");
                cout << "当前A集合: ";
                A.display();
                system("pause");
                break;

            case 4:
            	system("cls");
                cout << "当前B集合: ";
                B.display();
                system("pause");
                break;

            case 5: {
            	system("cls");
                LinkedList result = LinkedList::intersection(A, B);
                cout << "A和B交集: ";
                result.display();
                system("pause");
                break;
            }

            case 6: {
            	system("cls");
                LinkedList result = LinkedList::difference(A, B);
                cout << "A和B差集: ";
                result.display();
                system("pause");
                break;
            }

            case 7: {
            	system("cls");
                LinkedList result = LinkedList::unionSet(A, B);
                cout << "A和B的并集: ";
                result.display();
                system("pause");
                break;
            }

            case 8:
            	while()
                cout << "退出成功..." << endl;
                return 0;

            default:
                cout << "无效选项. 请重新输入." << endl;
        }
    }

    return 0;
}
