#include <bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string str;long long k=100,n=0;
    for(;k>n*(n-1)/2;n++);
    str+='a'+k-(n-1)*(n-2)/2;
    for(int i='a'+n-1;i>='a';i--)
        if(i!=str[0])str+=i;
    cout<<str;}
