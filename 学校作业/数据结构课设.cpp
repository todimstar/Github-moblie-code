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
    Node* head;  //5.29初审：private成员可添加以丰富拓展 

public:
    LinkedList() : head(NULL) {}

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
    cout << "1. Insert into Set A" << endl;
    cout << "2. Insert into Set B" << endl;
    cout << "3. Display Set A" << endl;
    cout << "4. Display Set B" << endl;
    cout << "5. Intersection of A and B" << endl;
    cout << "6. Difference of A and B" << endl;
    cout << "7. Union of A and B" << endl;
    cout << "8. Exit" << endl;
}

int main() {
    LinkedList A, B;
    int choice;
	string value;//5.30凌晨为单次输入预留12空间 //5.30凌晨直接string 

    while (true) {
    	system("cls");  //刷新一波 
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            	system("cls");
                cout << "Enter value to insert into Set A: ";
                cin >> value;
                A.insert(value);
                break;

            case 2:
            	system("cls");
                cout << "Enter value to insert into Set B: ";
                cin >> value;
                B.insert(value);
                break;

            case 3:
            	system("cls");
                cout << "Set A: ";
                A.display();
                break;

            case 4:
            	system("cls");
                cout << "Set B: ";
                B.display();
                break;

            case 5: {
            	system("cls");
                LinkedList result = LinkedList::intersection(A, B);
                cout << "Intersection of A and B: ";
                result.display();
                break;
            }

            case 6: {
            	system("cls");
                LinkedList result = LinkedList::difference(A, B);
                cout << "Difference of A and B: ";
                result.display();
                break;
            }

            case 7: {
            	system("cls");
                LinkedList result = LinkedList::unionSet(A, B);
                cout << "Union of A and B: ";
                result.display();
                break;
            }

            case 8:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
