#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c;
    double sum=0;
    double x1,x2;
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a==0)
    {
        printf("Not quadratic equation");
        return 0;
    }
    sum=(b*b)-(4*a*c);
          if(sum>0)
        {
        	x1=((-b)-sqrt(sum))/(2*a);
        	x2=((-b)+sqrt(sum))/(2*a);
        	 printf("x1=%.2lf;x2=%.2lf",x1,x2);
        }
        else if(sum==0)
        {x1=(-b)/(2*a);
             printf("x1=x2=%.2lf",x1);
        }
    return 0;
}
