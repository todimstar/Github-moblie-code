#include<iostream>
#include<cstring>
using namespace std;
#define MAX 10
int r(const char* ch){
    int i,len=strlen(ch),sum=0;
    for(i=0;i<len;i++){
        sum+=ch[i]-'0';
        if(i<len-1)sum=sum*10;
    }return sum;
}
bool run(int year){// 应该对了吧//不是整百年被4整除即可，是整百年得被400整除
    if(year%100!=0){
        if(year%4==0)
            return true;
    }else if(year%400==0)return true;
    return false;
}
int yue[]={29,31,28,31,30,31,30,31,31,30,31,30,31};
int main (){
	char ay[5],am[3],ad[3];
    char by[5],bm[3],bd[3];
	scanf("%4s%2s%2s",ay,am,ad);
    scanf("%4s%2s%2s",by,bm,bd);
	int ayear=r(ay),amm=r(am),aday=r(ad);
    int byear=r(by),bmm=r(bm),bday=r(bd);
    int d=0;
    //printf("%d %d %d\n%d %d %d",ayear,amm,aday,byear,bmm,bday);
    if(ayear==byear){
        if(amm<=2||bmm<=2){
            
        }else{bool f=amm<bmm;
            int ia=amm<bmm?amm:bmm,ib=amm<bmm?bmm:amm;
            for(;ia<ib;ia++){
                d+=yue[ia];
            }if(f)d+=bday;
              else d+=aday;
        }
    }
    printf("%d",d);
	return 0;
}
