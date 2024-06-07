#include <stdio.h>
int main() //命令行参数
{
    int ch;//定义文件类型指针
    FILE *fp;//判断命令行是否正确
    /*if(argc!=2)
    {
        printf("Error format,Usage: display filename1\n");
        return 0;; //键入了错误的命令行，结束程序的执行
    }*/
    //按读方式打开由argv[1]指出的文件
    if((fp=fopen("9992.in","r"))==NULL)
    {
        printf("The file <9992.in> can not be opened.\n");//打开操作不成功
        return 0;;//结束程序的执行
    }
    //成功打开了argv[1]所指文件
    ch=fgetc(fp); //从fp所指文件的当前指针位置读取一个字符
    while(ch!=EOF) //判断刚读取的字符是否是文件结束符
    {
        putchar(ch); //若不是结束符，将它输出到屏幕上显示
        ch=fgetc(fp); //继续从fp所指文件中读取下一个字符
    } //完成将fp所指文件的内容输出到屏幕上显示
    fclose(fp); //关闭fp所指文件
    return 0;
}
