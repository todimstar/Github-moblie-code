#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ss{
	char name[5];
	int age;
}s[3];
int compare(const void *a,const void *b){
    return *(int *)a-*(int *)b;//====此为int顺排b-a则为逆序 
}
int struct_compareint(const void* p1,const void *p2){//==对结构内int排序 
	return ((struct ss*)p1)->age-((struct ss*)p2)->age;
}
int struct_comparechar(const void* p1,const void *p2){//==对结构内char排序 //哦没事了name用成age了 
	return strcmp(((struct ss*)p1)->name,((struct ss*)p2)->name);
}
int main (){
    int T,n,m,i,t,jg;
    
    
    scanf("%d",&T);
   while(T--){
       scanf("%d",&n);
       int a[114514]={0};
       for(i=0;i<n;i++){
           scanf("%d",&a[i]);
       }jg=n;
       qsort(a,n,sizeof(int),compare);//=======函数快排Nb=====!!!!!===== 
       for(i=0;i<n;i++){
           if(a[i]==a[i+1]){
               jg--;
           }
       }
       printf("%d\n",jg);
   }
    
    return 0;
}
//自抄结构字符快排函数报警告;
//全抄运行如下：

/*//使用qsort()函数按姓名排序结构体
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//创建结构体
struct Stu
{
	char name[20];
	int age;
};
 
//compar_按姓名排序
int compar_Stu_name(const void* p1, const void* p2)
{
	return strcmp(((struct Stu*)p1)->name, ((struct Stu*)p2)->name);
}
 
int main()
{
	struct Stu s[3] = { {"zhangsan",20} ,{"lisi",30},{"wangmazi",25} };
	size_t num = sizeof(s) / sizeof(s[0]);
	size_t sz = sizeof(s[0]);
 
	qsort(s, num, sz, compar_Stu_name);
    //打印结果
	for (int i = 0; i < 3; i++)
	{
		printf("%s,%d\n", s[i].name, s[i].age);
	}
	return 0;
}*/ 
