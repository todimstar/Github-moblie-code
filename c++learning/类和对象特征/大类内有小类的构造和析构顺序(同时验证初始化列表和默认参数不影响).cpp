#include<iostream>

using namespace std;

class jay{
public:
	jay(int ab) {
		cout<<"jay的构造"<<endl;
        a=ab;

	}
    ~jay(){
        cout<<"jay的析构"<<endl;
    }
    void out(){
		cout<<a;
	}
	
private:
	int a;
	//int* exent;
}; 

class Person{
public:
	Person (int ab=1) :ljk(10),a(ab){//初始化列表加默认参数结合运用不影响 
		cout<<"Person的构造"<<endl;
        //a=ab;
		cout<<a<<"ljk=";ljk.out();
	}
    ~Person(){
        cout<<"Person的析构"<<endl;
    }
	
private:
	int a;
	jay ljk;
	//int* exent;
}; 
int main (){
    Person(404);//临时对象
    return 0;
}
