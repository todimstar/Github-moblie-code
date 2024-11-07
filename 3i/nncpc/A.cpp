#include<iostream>

using namespace std;

int main (){
    int T;
    int a,b,c,d;
    cin>>T;
    while(T--){
    
        cin>>a>>b>>c>>d;

        int acnt=0,ccnt=0;//记录a,c电梯的距离
        if(a == -1){//下行或到达，之后的行为都是下行
            acnt += b-1;
        }else if(a>b) acnt = a-1;
        else{//a<b--->abs(a-b)
            acnt += (b-1)+abs(a-b);//上行再下行
        }
        if(c == -1){//下行或到达，之后的行为都是下行
            ccnt += d-1;
        }else if(c>d) ccnt = c-1;
        else{//c<d--->abs(c-d)
            ccnt += abs(c-d)+(d-1);//上行再下行
        }
        if(acnt > ccnt)cout<<2<<endl;
        else if(acnt == ccnt)cout<<0<<endl;
        else cout<<1<<endl;

    }

    return 0;
}