#include<iostream>
#include<map>
#include<string>
using namespace std;

int main (){
    int N;
    cin>>N;

    map<string,int> gz;//关注
    map<string,double> dz;//点赞
    string s;
    for(int i=0;i<N;i++){
        cin>>s;
        gz[s]=1;
    }
    int M,cnt;
    long long sum;//总点赞
    cin>>M;

    for(int i=0;i<M;i++){
        cin>>s>>cnt;
        dz[s]=cnt;
        sum+=cnt;
    }
    double P = sum/M;//平均数
    //cout<<"P= "<<P<<" "<<(P>29.75)<<endl;
    bool have=false;

    for(auto i:dz){
        //cout<<"i.second="<<i.second<<endl;
        if(!gz[i.first] && i.second>P){//无此人且大于平均数
            cout<<i.first<<endl;
            cout<<"PTA炸了";
            have=true;
        }
    }//cout<<gz["Ammy"]<<"-"<<gz["Cath"]<<endl;
    if(!have)cout<<"Bing Mei You"<<endl;
    
    return 0;
}