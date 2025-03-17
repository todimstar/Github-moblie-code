#include<iostream>//算法注释：排序	，心得：回顾qsort	，题目网址：
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string re(const string& str){
	string t="";
	for(int i=str.size()-1;i>=0;i--){
		t+=str[i];
	}return t;
}

int comp(const void* a,const void* b){
	return (*(int*)b)-(*(int*)a);
}

int zh(vector<int>& t){
	int jg=0;
	for(int i:t){
		jg=jg*10+i;
	}return jg;
}

int main (){
	string str;
	vector<int> l;
	cin>>str;
	for(int i=str.size()-1;i>=0;i--){
		l.push_back(str[i]-'0');
	}
	qsort(&l[0],l.size(),sizeof(l[0]),comp);//大到小 
	
	int a=zh(l);//左大
	sort(l.begin(),l.end());
	int b= zh(l);//右小
	int c=a-b,i=1;
	cout<<i++<<": "<<a<<" - "<<b<<" = "<<c<<endl;
	
	while(c!=495){
		for(int i=0;i<3;i++){
			l[i]=c%10;
			c/=10;
		}
		qsort(&l[0],l.size(),sizeof(l[0]),comp);//大到小 
		a=zh(l);//左大
		sort(l.begin(),l.end());
		b= zh(l);//右小
		c=a-b;
		cout<<i++<<": "<<a<<" - "<<b<<" = "<<c<<endl;
	}
	
	return 0;
}
