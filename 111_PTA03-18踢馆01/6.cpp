#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main (){
    int N;
    cin>>N;
    cin.ignore();
    string str;
    getline(cin,str);
    int len = str.size();
    //cout<<str<<" "<<len;
    int vlen=len/N;//列数
    if(len%N){
        vlen++;
    }
    vector<string> outstrs(vlen+13);

    for(int i=0;i<vlen;i++){
        for(int j=0;j<N;j++){
            if((i*N+j)<len)outstrs[i]+=str[i*N+j];
            else{
                outstrs[i]+=' ';
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=vlen-1;j>=0;j--){
            cout<<outstrs[j][i];
        }cout<<'\n';
    }
    
    return 0;
}