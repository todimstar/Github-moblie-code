/*1.	集合运算
题目说明：以单链表的形式表示一个集合，试编写算法实现：
（1）求出两个集合A和B的交集，即 A∩B；
（2）求出两个集合A和B的差集，即 A- B；
（3）求出两个集合A和B的并集，即 A∪B。
要求：A和B集合是由任意输入的数据构建的单链表，不是程序定死的。
*/

#include <iostream>
#include<string>		//5.29：打算添加系统刷新函数 //5.30直接上string 
#include<conio.h>		//仅windows的全局检测 
#include<cstdlib>		//给system
#include<limits> 		//给那个numeric_limits忽略输入 
using namespace std;

struct Node {
	string data; //5.29：int改char //5.30凌晨 char直接string方便内存管理
	Node* next=NULL;
};

class LinkedList {
	private:
		Node* head = NULL; //5.29：private成员可添加以丰富拓展
		int Length = 0;
	public:


		void insert(const string& value) {  //5.30修改传参string
			Node* newNode = new Node;
			newNode->data = value;
			newNode->next = head;//头插
			head = newNode;
			Length++;
		}
		int deletedata(Node* finded){
			if(finded==NULL)return 0;
			Node* Fhead = head;
			while (Fhead) {//当链表没到头时 
				if (Fhead->next == finded){//为finded的上一个  
					if(finded->next){//finded不是链表最后一个 
						Node* Flast=finded->next;//Flast指向后位 
						delete finded;//删掉finded ？？貌似是这里删除的地方被访问了，并且跳转到集合运算函数去了 
						Fhead->next=Flast;//next链上后位 
						}
					else{Fhead->next=NULL;}//是最后一个 
					break;
				}if(Fhead==finded){head=finded->next;delete finded;break;}//就是第一个,因为是头指针链表所以要特判删除 
				Fhead=Fhead->next;//推进指针寻找 
			}return 1;
		}

		void display() const { //保证不会对成员改动
			Node* current = head;
			if (!current)cout << "空...";
			while (current != NULL) {
				cout << current->data << " -> ";
				current = current->next;
			}
			cout << endl;
		}

		Node* getHead() const { //为了下面的静态成员函数
			return head;
		}
		int length() const {
			return Length;
		}
		Node* finddata(string value) const {//查找该值存在则返回指针
			Node* Fhead = head;
			while (Fhead) {
				if (Fhead->data == value)return Fhead;
				Fhead=Fhead->next;
			}
			return NULL;
		}

		static LinkedList intersection(LinkedList& A, LinkedList& B) {//交集
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
		//LinkedList Intersection(LinkedList& A,LinkedList& B){

		//}

		static LinkedList difference(LinkedList& A, LinkedList& B) {//三个都不依赖于特定实例，都可以是static静态成员函数
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

		static LinkedList unionSet(LinkedList& A, LinkedList& B) {  //5.29：static没记错是把函数在编译时补进调用处
			//6.12:记错啦,inline内联函数才是
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

void displayMenu(const LinkedList& A, const LinkedList& B) {
	printf("------------集合运算------------\n");
	cout << "当前A集合成员:" ;
	A.display();//因为传入是const类型，所以只能调用const成员函数以保证不会对对象进行修改
	printf("\n");
	cout << "当前B集合成员:" ;
	B.display();
	printf("\n");
	cout << "*-----------------------------增\n";
	cout << "1. 单个新增A集合成员" << endl;
	cout << "2. 单个新增B集合成员" << endl;
	cout << "3. 批量新增A集合成员*" << endl;
	cout << "4. 批量新增B集合成员*" << endl;
	cout << "*-----------------------------删\n";
	//cout << "删除某集合成员\n";
	cout << "5.删除A中指定单个成员*"<<endl;
	cout << "6.删除B中指定单个成员*"<<endl;
	cout << "*-----------------------------改\n";
	//cout << "修改某集合成员\n";
	cout << "7.修改A中单个成员*"<<endl;
	cout << "8.修改B中单个成员*"<<endl;
	cout << "*-----------------------------运算\n";
	cout << "9. 求出A和B交集(A∩B)" << endl;
	cout << "10. 求出A和B差集(A - B)" << endl;
	cout << "11. 求出B和A差集(B - A)*" << endl;
	cout << "12. 求出A和B的并集(A∪ B)" << endl;
	cout << "13. 退出集合运算" << endl;
}

int oneadd(LinkedList& L, char aorb) {
again:
	string value;//切好备用
	string temp;//提高抗乱输入能力:string输入类型，if判断switch 好处:错回不用cin.clear() 
	system("cls");
	printf("----新增单个%c集合成员----\n", aorb);
	cout << "按1开始新增，按0返回主菜单";
	cin >> temp;
	
	if(temp=="1") {
		printf("输入新增的%c集合成员: ", aorb);
		cin >> value;
		L.insert(value);
		system("pause");
		return 1;
	} 
	else if(temp=="0"){return 0;}
	else{
		cout << "回1或0就行 再试试?\n";
		//cin.clear();
		system("pause");
		goto again;
	
	}
}

void moreadd(LinkedList& T, char aorb) {
	//system("cls"); 
	//printf("----批量新增%c集合成员----\n", aorb);//有了onesee就不用了
	string value;
	printf("输入新增的%c集合成员(结束批量输入\"end\"): ", aorb);
	while (cin >> value && value != "end") {
		T.insert(value);//缓存新增
	}
	if (std::cin.fail()) {
		std::cout << "输入错误或遇到了文件结束符。\n";
		std::cin.clear(); // 清除错误状态
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误输入
	}
}

int moreaddchange(LinkedList& T) {
	char temp = '0';
	do {
		system("cls");
		cout << "-------修改本次新增-------\n";
		cout << "本次新增：";
		T.display();
		printf("\n");
		if (T.length()) {
			string value;
			cout << "请选择要修改的值(选)：";
			cin >> value;
			//查找函数
			Node* find = T.finddata(value);
			if (find) {
				cout << "请输入修改值(改)：";
				cin >> value;
				find->data = value;
				return 1;//修改成功
			} else {
				cout << "查无此值,任意键重选,放弃修改0";

				cin >> temp;
				if (temp == '0')return 0; //放弃修改
			}
		}else{
			cout<<"本次无新增，";
			return 0;
		} 
	} while (temp != '0');
	cout<<"warning...\n";
	return -1;//以普遍理性而论，不会到这 
}

int moreaddview(LinkedList& L, char aorb) {//新增成员系统视图与其main 
	LinkedList T;
	int chose; //无法抵抗乱输入 
	int onesee = 0;//设置ststic会导致第二次调用延续onesee 
	do {
		system("cls");
		printf("#--------新增成员系统--------#\n");
		printf(" -----批量新增%c集合成员----- \n", aorb);
		
		cout<<"当前已新增：";T.display();cout<<endl; 
		if (onesee==0) {//首次进入选项 
			cout << "按1开始新增，按0返回主菜单";
			cin >> chose;
			onesee=1;
		}else if(onesee==2){
			cout << "回1继续新增，按0提交本次新增并返回主菜单，2继续修改某个新增，3放弃本次新增";
			cin >> chose;
		}

		switch (chose) {
			case 1: {
				moreadd(T, aorb);
				cout << "回1继续新增，按0提交本次新增并返回主菜单，2修改某个新增，3放弃本次新增";
				cin >> chose;
				break;
			}
			case 2: {
				if (moreaddchange(T)){
					cout << "修改成功!\n";
					onesee=2;
				}else{
					cout<<"已放弃修改\n";
					chose=2;
				}system("pause");
				break;
			}
			case 0: {							//得保证进来的T都是要提交的
				if (T.length()) {
					Node* thead = T.getHead();
					while (thead) {
						L.insert(thead->data);//L插入Thead;
						thead = thead->next;
					}
				}
				return 0;
			}
			case 3: {
				return 0;
			}
			default: {
				cout << "回0、1、2就行 再试试?\n";
				cin.clear();//需要加ignore 
				system("pause");
			}
		}
		//system("pause");
	} while (true);
	cout<<"warning...\n"; 
	return -1;//同样不应该会走到这 
}

int onechange(LinkedList& L, char aorb) {//修改单个 
again:
	
	string temp;//提高抗乱输入能力:string输入类型，if判断switch 好处:错回不用cin.clear() 
	system("cls");
	printf("----修改单个%c集合成员----\n", aorb);
	cout<<"当前"<<aorb<<"集合成员：";L.display(); 
	cout << "\n按1开始修改，按0返回主菜单";
	cin >> temp;
	
	if(temp=="1") {
		string value;
		printf("输入要修改的%c集合成员: ", aorb);
		cin >> value;
		Node* find=L.finddata(value);
		if(find){
			cout<<"找到此值\n";
			cout<<"请输入修改值(改)：";
			cin>>value;
			find->data=value;
			return 1;//修改成功 
		}else{
			cout<<"查无此值，任意键重选，放弃修改0";
			cin>>temp;
			if(temp=="0")return 0;//放弃修改 
			else{goto again;}
		}
	} 
	else if(temp=="0"){return 0;}
	else{
		cout << "回1或0就行 再试试?\n";
		//cin.clear();
		system("pause");
		goto again;
	
	}
}

int onedelete(LinkedList& L, char aorb){
	while(true){
		string temp;
		system("cls");
		printf("----删除单个%c集合成员----\n", aorb);
		cout<<"当前"<<aorb<<"集合成员：";L.display(); 
		cout << "\n按1开始选择删除元素，按0返回主菜单";
		cin >> temp;
		
		if(temp=="1") {
			string value;
			printf("输入想删除的%c集合成员: ", aorb);
			cin >> value;
			Node* find=L.finddata(value);
			if(find){
				cout<<"找到此值\n";
				again:
				cout<<"确定删除元素"<<find->data<<"?\nY(y)\\N(n)\n";
				cin>>value;
				if(value=="Y"||value=="y"){
					if(L.deletedata(find))return 1;//删除成功
					else{cout<<"warning in delete find";system("pause");return -1;}
				}else if(value=="N"||value=="n"){
					
				}
				else {
					cout << "回Y(y)或N(n)就行 再试试?\n";
					system("pause");
					goto again;
				} 
			}else{
				cout<<"查无此值，任意键重选，放弃删除0";
				cin>>temp;
				if(temp=="0")return 0;//放弃 
				//else进循环 
			}
		} 
		else if(temp=="0"){return 0;}
		else{
			cout << "回1或0就行 再试试?\n";
			
			system("pause");
		}
	}cout<<"warning in delete end\n";
	system("pause");
	return -1;
}

int main() {
	LinkedList A, B;
	int choice;
	string value;

	while (true) {
		system("cls");  //刷新一波
		displayMenu(A, B);
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1: {
				oneadd(A, 'a');
				break;
			}
			case 2: {
				oneadd(B, 'b');
				break;
			}
			case 3: {
				moreaddview(A,'A'); 
				break;
			}

			case 4: {
				moreaddview(B,'B');
				break;
			}
			
			case 7:{
				onechange(A,'A');
				break;
			}
			case 8:{
				onechange(B,'B');
				break;
			}
			case 5:{
				onedelete(A,'A'); 
				break; 
			}
			case 6:{
				onedelete(B,'B');
				break; 
			}
			case 9: {
				system("cls");
				LinkedList result = LinkedList::intersection(A, B);
				cout<<"当前A集合成员：";A.display();printf("\n");
				cout<<"当前B集合成员：";B.display();printf("\n");
				cout<<"-----------------------------------------\n";
				cout << "A和B交集 即(A∩B): ";
				result.display();
				cout<<"-----------------------------------------\n";
				system("pause");
				break;
			}

			case 10: {
				system("cls");
				LinkedList result = LinkedList::difference(A, B);
				cout<<"当前A集合成员：";A.display();printf("\n");
				cout<<"当前B集合成员：";B.display();printf("\n");
				cout<<"-----------------------------------------\n";
				cout << "A和B差集 即(A - B): ";
				result.display();
				cout<<"-----------------------------------------\n";
				system("pause");
				break;
			}

			case 11: {
				system("cls");
				LinkedList result = LinkedList::difference(B, A);
				cout<<"当前A集合成员：";A.display();printf("\n");
				cout<<"当前B集合成员：";B.display();printf("\n");
				cout<<"-----------------------------------------\n";
				cout << "*B和A差集 即(B - A): ";
				result.display();
				cout<<"-----------------------------------------\n";
				system("pause");
				break;
			}

			case 12: {
				system("cls");
				LinkedList result = LinkedList::unionSet(A, B);
				cout<<"当前A集合成员：";A.display();printf("\n");
				cout<<"当前B集合成员：";B.display();printf("\n");
				cout<<"-----------------------------------------\n";
				cout << "A和B的并集 即(A∪ B): ";
				result.display();
				cout<<"-----------------------------------------\n";
				system("pause");
				break;
			}

			case 13: {
				//while()
				cout << "退出成功..." << endl;
				return 0;
			}
			default:
				cout << "无效选项. 请重新输入." << endl;
				cin.clear();  
				//cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("pause");
				
		}
	}

	return 0;
}
