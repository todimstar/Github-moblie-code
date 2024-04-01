#include<stdio.h>
#include<math.h>
int main(){
    float a,b,c;
    float derta;
    
    scanf("%f %f %f",&a,&b,&c);
    if(a==0){
        printf("Not quadratic equation");
		return 0;//若此不return 0则下方得else if补条件,不然都执行... 
    }
    derta=(b*b)-(4*a*c);
    if(derta==0){
        printf("x1=x2=%.2f",(-b)/(2*a));//66错在公式背错... 现在改好了是(-b+-sqt(derta))/2a...
    }
    else{
        printf("x1=%.2f;x2=%.2f",(-b-sqrtf(derta))/(2*a),(-b+sqrtf(derta))/(2*a));//运算优先级...*./.得带括号 
    }
    
    return 0;
}
