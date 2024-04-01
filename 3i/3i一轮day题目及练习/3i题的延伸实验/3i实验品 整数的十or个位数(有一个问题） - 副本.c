
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
//#include<stdio.h> 
//#include<string.h>
//int main ()
//{
//	char a[]="1234567890";
////	int len = strlen(a);//“===问题1===”：为什么strlen赋值给len是固定值2这会是1了难道是地址? (此情况存在于char a[999];时... 
//    
//	scanf("%s",a);//好像数组的话就不用&诶 
//	
// 	int len = strlen(a);//“===问题2===”：起飞，把其定义到后面就对了，但是为啥？ 
// 	
//    printf("len=%d\n",len); 
//    
//    printf("strlen(a)=%d\n",strlen(a));//====问题3====:]将a[]=某物之后strlen(a)不超过原定义的范围便都正确
//	//超出即a[len-1]与strlen(a)都出错
//	//但len是后输入的长度... 
//    
//	printf("末位数是%c\n",a[len-1]);//还记得吗因为地址从0开始 
//	
//	//“===Bug===”: 因为使用的是字符串，所以有个bug，若是输入了不是数字也算一位数了，so有无纯数字的方法呢 
//	
//	return 0;
//}

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

#include<stdio.h> 
#include<string.h>
int main ()
{
	int a[]={1,2,3};
    
	scanf("%s",a);//%d则输入无效输出值很傻比，%s则len和strlen正常但a[len-1]怪无规律。 
	
 	int len = strlen(a); 
 	
    printf("len=%d\n",len); 
    
    printf("strlen(a)=%d\n",strlen(a));//[[char时]]====问题3====:]将a[]=某物之后strlen(a)不超过原定义的范围便都正确
	//超出即a[len-1]与strlen(a)都出错
	//但len是后输入的长度... 
    
	printf("末位数是%d\n",a[len]);//还记得吗因为地址从0开始 
	
	//“===Bug===”: 因为使用的是字符串，所以有个bug，若是输入了不是数字也算一位数了，so有无纯数字的方法呢 
	
	return 0;
}
