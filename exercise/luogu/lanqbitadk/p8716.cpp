#include<iostream>	
#include<vector>
#include<string>

using namespace std;

const int N =1e9+10;
typedef long long ll;
int T,n;

int zh(char *a,bool flag){
    int ans=0;
    if(flag){
        for(int i=0;i<4;i++){
        ans*=10;
        ans+=a[i]-'0';
        }
    }else{
        for(int i=3;i>=0;i--){
        ans*=10;
        ans+=a[i]-'0';
        }
    }
    return ans;
}
bool mothbig[12]={1,0,1,0,1,0,1,1,0,1,0,1};

bool yearbig(int x){
    if(x%400==0){
        return true;
    }else if(x%100==0){
        return false;
    }else if(x%4==0){
        return true;
    }else{
        return false;
    }
}

bool check(int x){
    int day=x%100;
    int moth=(x/100);
    if(day>31||(moth==2 && yearbig(x) && day>28) || (moth==2 && !yearbig(x) && day>29)){
        return false;
    }else{
        return true;
    }
}//太极儿难调了，不调了

int main (){
    char a1[4],a2[4];
    for(int i=0;i<4;i++){
        cin>>a1[i];
    }
    for(int i=0;i<4;i++){
        cin>>a2[i];
    }int num=max(zh(a1,1),zh(a2,0));
    if(zh(a1,1)==zh(a2,0)){
        while(!check(num)){
            num=bild(num);
        }
    }else{
        
    }
    vector<string> table;
    char nums[9]="10100101";//打表算后，输出大于输入的后两位即可

	return 0;
}
/* 题解：回文用双指针，判断合法用/和打表，其余暴力*
#include<bits/stdc++.h>
using namespace std;
int months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//打个月份表
//判断合法 
bool check_valid(int date){
    int year=date/10000;
    int month=date%10000/100;
    int day=date%100;//分离年月日 
    if(day==0||month<=0||month>12)return false;//显然的不合法情况 
    if(month!=2&&day>months[month])return false;//月份不是2，day不合法就不合法 
    if(month==2){//月份是2 
        if((year%4==0&&year%100!=0)||(year%400==0))if(day>29)return false;//是闰月， day必须<=29 
        else if(day>28)return false;//是平月，day必须<=28 
    }
    return true;
}
//判断回文 
bool check_huiwen(string s){
	int len=s.size();
    for(int i=0,j=len-1;i<j;i++,j--)//i从前往后，j从后往前扫一遍 
        if(s[i]!=s[j])return false;//不对称，就不回文 
    return true;
}
//判断ABABBABA 
bool check_ABAB(string s){
	if(check_huiwen(s)){//首先它得是个回文数 
		//接下来只需判断前4位是否合法 
		if(s[0]!=s[2]||s[1]!=s[3]||s[0]==s[1])return false;
		//结合ABABBABA思考 
		return true;
	}
	return false;
}
int main(){
    int n;cin>>n;
    bool flag=0;
    for(int i=n+1;;i++){//枚举回文数 
        if(check_valid(i)){//合法 
            string s=to_string(i);//仅在C++11标准及以后出现，比较好用 
            if(check_huiwen(s)&&!flag){//输出第一个回文数 
                cout<<i<<endl;
                flag=1;
            }
            if(check_ABAB(s)){//输出第一个特殊回文数 
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}
*/