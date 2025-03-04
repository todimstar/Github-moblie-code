#include<iostream>
#include<algorithm>
using namespace std;

int n,minu;
string str;
const string index="123456";
bool flag;

void change(string &str){
    for(int i=0;i<str.size();i++){
        if(str[i]=='m')str[i]='1';
        else if(str[i]=='n')str[i]='2';
        else if(str[i]=='s')str[i]='3';
        else if(str[i]=='f')str[i]='4';
        else if(str[i]=='d')str[i]='5';
        else if(str[i]=='x')str[i]='6';
    }
}

void maopao(string& str){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(str[i]>str[j]){
                swap(str[i],str[j]);
                minu++;
            }
        }
    }
}

int main (){
    
    int T;
    cin>>T;
    while(T--){
        cin>>n>>str;

        if(str.size()==6){
            minu=0;
            change(str);
            maopao(str);
            if(str==index)cout<<minu<<endl;
            else cout<<-1<<endl;
        }
        else cout<<-1<<endl;
    }
    
    return 0;
}