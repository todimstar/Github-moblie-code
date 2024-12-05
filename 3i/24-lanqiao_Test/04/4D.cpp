#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<cstring>
#include<queue>

using namespace std;

const int N =500+13;
typedef long long ll;
struct point{
    int x,y;
};
int T,n1=1,n2=1;
double m1,m2,sum;
double v1=1,v2=1;
bool flag=true;//1为n1,0为n2


int main (){
    cin>>T;
	while(T--){
        
        if(flag){
            if(m1<10*n1){
                m1+=v1;
                sum+=v1;
            }else if(m2<8*n1){
                m2+=v2;
                sum+=v2;
            }

            if(m1>=10*n1 && m2>=8*n1){//可升1
                m1-=10*n1,m2-=8*n1;//扣材料
                n1++;//升级
                v1+=0.25;//发补偿
                flag=!flag;//转目标
            }
        }else{
            if(m1<8*n2){
                m1+=v1;
                sum+=v1;
            }else if(m2<10*n2){
                m2+=v2;
                sum+=v2;
            }

            if(m1>=8*n2 && m2>=10*n2){
                m1-=8*n2,m2-=10*n2;//扣材料
                n2++;//升级
                v2+=0.25;//发补偿
                flag=!flag;//转目标
            }
        }//printf("%.2lf %.2lf %.2lf\n",sum,m1,m2);
    }
	printf("%.2lf\n",sum);
	
	return 0;
}
