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


void f(){
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
	}
	
}


int main (){
	f();
	return 0;
}
