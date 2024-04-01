#include <stdio.h>
int main(void){
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a==0){
        printf("Not quadratic equation");
    }else{
         if(pow(b,2)-4*a*c==0){
        double x ;
        x = (-b)/(2*a);
        printf("x1=x2=%.2f",x);
    }else if(pow(b,2)-4*a*c>0){
             double x1,x2;
             double flag = pow(b,2);
             x1 = ((-b)-sqrt(flag-4*a*c))/(2.0*a);
             x2 = ((-b)+sqrt(flag-4*a*c))/(2.0*a);
             printf("x1=%.2f;",x1);
             printf("x2=%.2f",x2);
         }
    }
   
    return 0;
}
