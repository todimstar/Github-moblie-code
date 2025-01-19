#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<vector>
#include<string>

using namespace std;

const int N =37;
typedef long long ll;
int n;
char a[N]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


int main (){

	
	cin>>n;
    for(int i=1;i<n;i++){
        
    	for(int j=1;j<=i;j++){
            int mul=i*j;
    		cout<<a[i]<<'*'<<a[j]<<'=';
            vector<char> temp;
            temp.push_back(a[mul%n]);
            while(mul/n){
                mul/=n;
                temp.push_back(a[mul%n]);
            }
            for(int k=temp.size()-1;k>=0;k--){
                cout<<temp[k];
            }cout<<' ';
		}cout<<endl;
	}
	
	
	return 0;
}
