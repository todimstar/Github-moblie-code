#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ss{
	char name[5];
	int age;
}s[3];
int compare(const void *a,const void *b){
    return *(int *)a-*(int *)b;//====��Ϊint˳��b-a��Ϊ���� 
}
int struct_compareint(const void* p1,const void *p2){//==�Խṹ��int���� 
	return ((struct ss*)p1)->age-((struct ss*)p2)->age;
}
int struct_comparechar(const void* p1,const void *p2){//==�Խṹ��char���� //Ŷû����name�ó�age�� 
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
       qsort(a,n,sizeof(int),compare);//=======��������Nb=====!!!!!===== 
       for(i=0;i<n;i++){
           if(a[i]==a[i+1]){
               jg--;
           }
       }
       printf("%d\n",jg);
   }
    
    return 0;
}
//�Գ��ṹ�ַ����ź���������;
//ȫ���������£�

/*//ʹ��qsort()��������������ṹ��
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//�����ṹ��
struct Stu
{
	char name[20];
	int age;
};
 
//compar_����������
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
    //��ӡ���
	for (int i = 0; i < 3; i++)
	{
		printf("%s,%d\n", s[i].name, s[i].age);
	}
	return 0;
}*/ 
