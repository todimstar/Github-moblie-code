#include<iostream>
#include<vector>
#include<algorithm> //非成员函数--倒转(可str可vector)std::reverse(str.begin(),str.end())
using namespace std;

//判断a,b谁长
bool compare(vector<int>& a,vector<int>& b){
    if(a.size()!=b.size()) return a.size()>b.size();
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]!=b[i]){
            return a[i]>=b[i];
        }
    }return true;
}

//C = A - B 仅适用于A>=B
vector<int> highsub(vector<int>& a,vector<int>& b){
    
	//开始计算
	vector<int> c;
	int sub;
    int t=0,lena=a.size();
	for(int i=0;i<lena;i++){
        t=a[i]-t;   //与借位消掉
        if(i<b.size())t-=b[i];  //默认了a>b
        c.push_back((t+10)%10);
        if(t<0)t=1; //判断下次的借位
        else t=0;
	}
    //去除前导零
    while(c.size()>1 && c.back() == 0)c.pop_back();

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

    if(compare(a,b)){
        vector<int> c = highsub(a,b);
        //倒转c
        reverse(c.begin(),c.end());

        for(auto i:c)cout<<i;
    }
    else {
        vector<int> c = highsub(b,a);

        //倒转c? 不如直接倒着输出...
        cout<<"-";
        for(int i=c.size()-1;i>=0;i--)cout<<c[i];
    }

	return 0;
}
