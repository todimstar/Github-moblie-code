#include<iostream>//算法注释：%注意+26防负数就行，心得：aa,一定要记得getline(cin,str,'\n')	，题目网址：https://pintia.cn/problem-sets/1889983872709570560/exam/problems/type/7?problemSetProblemId=1889983872730542083&page=0
#include<string>
#include<vector>
using namespace std;


int main (){
	int T;
	cin>>T;
	
	while(T--){
		int n,k;
		cin>>n>>k;
		getchar();
		string str,jg;
		getline(cin,str);
		
		/*char temp;
		for(int i=0;i<n;i++){
			temp = getchar();
			str+=temp;
		}getchar();*/
		//
		cout<<str<<endl;
		char t='0';
		for(int i=0;i<n;i++){
			if(str[i]!=' '){
				t=((((str[i]-'A')+(k%26)+26)%26)+26)%26+'A';
			}else{
				t=' ';
			}jg+=t;
		}
		cout<<jg<<endl;
	}
	
	
	return 0;
}
