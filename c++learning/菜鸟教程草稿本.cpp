#include<iostream>

using namespace std;
#include <stdio.h>

#define Debug 1
//#define Release 0

void test(){//==2.一些预处理的语句 
	
	#if Debug
		printf("Debuging\n");
	#elif !defined(Release)
		printf("what happened?__ No Debuging Don't had release\n");
	#elif Release
		printf("Releasing now\n");
	#else
		printf("what can i say? Are you Debuging now?\n");
	#endif
	cout<<"test over\n"<<endl;
}
int main(){
	
    int $a=0x99;
    printf("$%d\n",$a);//1.====c/c++其实还有个标识符$; 
    test();//==2.一些预处理的语句 
    
    enum mihoyo{b2,bbb,yuanshen,weiding,bt,_jql_}a;//==3.浅浅枚举一下米忽悠吧;(也可以在全局定义)
    char mhy[][10]={"b2","bbb","yuanshen","weiding","bt","_jql_"}; 
    a=b2;
    printf("mihoyo第%d件作品是%s\n",a,mhy[a]);
    
    return 0;
}
