#include<iostream>
#include<vector>
#include<algorithm> //非成员函数--倒转(可str可vector)std::reverse(str.begin(),str.end())
using namespace std;


vector<int> highadd(vector<int>& a,vector<int>& b){
	//开始计算
	vector<int> c;
	int t=0,lena=a.size(),lenb=b.size();
	for(int i=0;i<lena||i<lenb;i++){
		if(i<lena)t+=a[i];
		if(i<lenb)t+=b[i];
		c.push_back(t%10);
		t/=10;
	}
	if(t)c.push_back(1);


	return c;
}


int main (){
	int n;
	string A,B;

	cin>>A>>B;

    //使用前先倒序转换A,B进vector
	vector<int> a,b;
	int lena=A.size(),lenb=B.size();

	for(int i=lena-1;i>=0;i--)a.push_back(A[i]-'0');	//次次忘转换
	for(int i=lenb-1;i>=0;i--)b.push_back(B[i]-'0');

	vector<int> c = highadd(a,b);

	//倒转c
	reverse(c.begin(),c.end());

	for(auto i:c)cout<<i;
	return 0;
}
