#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main (){
    int N;
    cin>>N;
    string jg;

    while(N--){
        vector<string> strs(5);
        for(int i=0;i<4;i++){
            cin>>strs[i];
            //cout<<strs[i]<<" ";
        }//cout<<endl<<endl;
        for(int i=0;i<4;i++){
            if(strs[i][2] == 'T'){
                jg+='0'+(strs[i][0]-'A')+1;
                //cout<<strs[i][0]-'A'<<endl<<endl;
                break;
            }
        }
    }
    cout<<jg<<endl;

    return 0;
}