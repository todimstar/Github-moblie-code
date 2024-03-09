#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int run (int year){
    if(year%4==0){
        if(year%100)return 1;
        else if(year%400==0)return 1;
    }return 0;
}

int main (){
    long long sum=0;
    int i,cotn;
    int year=2000,y31[]={3,5,7,8,10,12},y30[]={4,6,9,11};
    int yue[13];
    int flag31,flag30;
    for(;year<=2000000;year++){
        flag31=0;cotn=1;
        memset(yue,0,sizeof(yue));
        flag30=0;
        for(i=2;i<=30;i++){
            if(year%i==0)cotn++;
        }if(year%31==0){
            flag31=1;
            cotn++;
        }sum+=cotn;
        for(i=2;i<=12;i++){
            if(year%i==0)yue[i]=1;
        }
        if(yue[2]==1){
            if(year%30==0)flag30=1;
            if(run(year)==1){
                if(year%29==0){
                    sum--;
                }
            }sum+=cotn-flag31-flag30;
        }for(i=0;i<6;i++){
            if(yue[y31[i]]==1)sum+=cotn;
        }if(flag31==1)cotn--;
        for(i=0;i<4;i++){
            if(yue[y30[i]]==1)sum+=cotn;
        }
    }printf("%lld",sum);
    return 0;
}
