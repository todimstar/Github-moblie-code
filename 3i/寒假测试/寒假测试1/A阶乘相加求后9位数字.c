#include<stdio.h>//======3i寒假测试一.A 
int main()
{
    long long int sum=0;
    for(int i=1;i<=66;i++)//阶乘大到40!之后的阶乘后9位数字都是0 
    {
        long long int sum1=1;
        int b=i;
        while(b)
        {
            sum1=sum1*b;
            sum1=sum1%1000000000;
            b--;
        }
        sum+=sum1;
        sum=sum%1000000000;
    }
    printf("%lld",sum);
}
