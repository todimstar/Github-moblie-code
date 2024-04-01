#include <stdio.h>

int main()
{
    int x = 0;
    int i = 0;
    scanf("%d", &x);//输入一个整数
    if (x==0) {
		i+=1; //完善了输入0无法正确输出1位数的bug 
	}
    while (x != 0)
    {
        x /= 10;//x除以10取整
        i++;//进行一次循环i+1
    }
    printf("%d位数", i);
    return 0;
}
