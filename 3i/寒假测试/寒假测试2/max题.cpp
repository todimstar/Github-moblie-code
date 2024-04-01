#include<iostream>
#include<cstdio>
using namespace std;
const long long N=2021041820210418;
int main (){
    long long l=1,w=1,h=N;
    int sum=0;
    for(;l<=N;l++){
        for(;w<=N;w++){
            for(;h>0;h--){
                if(l*w*h==N)sum++;
            }
        }printf("%lld\n",l); 
    }cout<<'\n'<<sum;
    return 0;
}
