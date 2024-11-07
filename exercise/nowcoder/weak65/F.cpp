#include<iostream>

using namespace std;

int n,m,k;

int zhuan(char* str,int n){
    int res=0;
    for(int i=n-1;i>=0;i--){
        if(str[i]='0')res += res<<i;
    }
    return res;
}

int main (){

    cin>>n>>m;
    char** str = new char*[n];
    int* bing = new int[n];

    for(int i=0;i<n;i++){
        str[i] = new char[m];
    }

    for(int i=0;i<n;i++){
        cin>>str[i];
        bing[i] = zhuan(str[i],n);
        cout<<bing[i]<<" ";
    }




    return 0;
}