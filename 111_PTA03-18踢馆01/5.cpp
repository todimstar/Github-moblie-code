#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main (){
    int a,b;
    cin>>a>>b;
    int c = a*b,d=0;
    while(c){
        d=d*10+c%10;
        c/=10;
    }
    cout<<d<<endl;
    return 0;
}