
//=====================指针还没找到倒着取,但可以总数减几得后某位=================== 


//#include<stdio.h>
//#include<string.h>
//int main() 
//{
//	char a[999];
//
//	
//	scanf("%s",a);
//	
//	printf("%d\n",strlen(a));
//	printf("%c\n",a[strlen(a)-2]); 
//	
//	
//	
//	return 0;
//}

//======================整数的个位数 3i 1010 ====================================================

////实验疑问品(改良后可用但有局限性)：但仍不知其理...待解决 ...又带出了一个问题 
#include<stdio.h> 
#include<string.h>
int main ()
{
	char a[999];
//	int len = strlen(a);//“===问题1===”：为什么strlen赋值给len是固定值2这会是1了难道是地址? ???
    
	scanf("%s",a);//好像数组的话就不用&诶 
	
 	int len = strlen(a);//“===问题2===”：起飞，把其定义到后面就对了，但是为啥？ 
 	
    printf("len=%d\n",len); 
    
    printf("%d长度\n",strlen(a));
    
	printf("%c位数\n",a[len-1]);//还记得吗因为地址从0开始 
	
	//“===Bug===”: 因为使用的是字符串，所以有个bug，若是输入了不是数字也算一位数了，so有无纯数字的方法呢 
	//有，那就是%10再/10，就能int且不用strlen,因为也用不了。 “===bug修复===” 
	
	return 0;
}

////正式版

//#include<stdio.h> 
//#include<string.h>
//int main ()
//{
//	char a[999];
//	
//	scanf("%s",a); 
//	
//	printf("%c",a[strlen(a)-1]);//为啥要-1来着,因为地址从0开始 
//	
//	return 0;
//} 
