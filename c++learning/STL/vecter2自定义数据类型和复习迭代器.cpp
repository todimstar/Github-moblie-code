#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Person
{
	public:
		int age=18;
		string country;
		
		Person()=default; 
		
		Person(int w_age,string w_country="China"){
			age=w_age;
			country=w_country;
		}
		string Return_Country(){return country;}
};


void f1(){
	Person s1;
	Person s2;
	Person s3=20;		//感觉可以调用那个含默认参数的有参构造 
	Person s4=Person(22);//显式构造 
	cout<<s1.Return_Country()<<"s1.country is"<<s1.country<<"kong";//验证了string严防死守，很好的控制了自己的内存 
	cout<<s2.Return_Country()<<"s2.country is"<<s2.country<<endl;
	
	
	vector<Person>a;
	a.push_back(s3);
	a.push_back(s4);
	for(vector<Person>::iterator sentinel=a.begin();sentinel!=a.end();sentinel++){
		cout<<"age="<<(*sentinel).age<<" country is "<<sentinel->country<<endl;
	}//迭代器在随机访问迭代器（如vector或array的迭代器中才可以进行加减操作++--; 
	//迭代器目前还是只遇到了可以当做指针的情况.
	//如vector<Person*>iterator,用迭代器访问就像二重指针一样，(*那个iterator)得到Person*再->指向成员
												//或者二重指针(*(*那个iterator)).指向的成员 
}

void f2(){
	vector<vector<int>>vw1;//vector<int,char>vw1;好好好，vector还只能收一个 
	vector<int>vn1,vn2;
	vn1.push_back(10);
	vn2.push_back(11);
	vw1.push_back(vn1);
	vw1.push_back(vn2);
	for(vector<vector<int>>::iterator it=vw1.begin();it!=vw1.end();it++){
		//(*it)--->VN(i)
		for(vector<int>::iterator vit=(*it).begin();vit!=(*it).end();vit++){
			cout<<*vit<<endl;
		}
	}
	
}

int main (){
	f1();
	f2();
	return 0;
}
