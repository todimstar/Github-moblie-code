#include<iostream>
using namespace std;

int main (){
    int N;
    cin>>N;
    
    while(N--){
        char ch;
        double H;
        cin>>ch>>H;
        if(ch=='F'){
            printf("%.2f\n",H*1.09);
        }else{
            printf("%.2f\n",H/1.09);
        }
    }


    return 0;
}