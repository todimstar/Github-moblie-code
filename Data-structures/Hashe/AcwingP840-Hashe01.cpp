/*维护一个集合，支持如下几种操作：

I x，插入一个整数 x
；
Q x，询问整数 x
 是否在集合中出现过；
现在要进行 N
 次操作，对于每个询问操作输出对应的结果。

输入格式
第一行包含整数 N
，表示操作数量。

接下来 N
 行，每行包含一个操作指令，操作指令为 I x，Q x 中的一种。

输出格式
对于每个询问指令 Q x，输出一个询问结果，如果 x
 在集合中出现过，则输出 Yes，否则输出 No。

每个结果占一行。

数据范围
1≤N≤105

−109≤x≤109
*/


#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;
//开放寻址--find()即可
//开放寻址弊端初始化的值如果是-1,0之类的，若输入的就是判断值会出现误以为没来的情况
//So,别初始化为-1,0之类的就行啦
const int N=100003,null=0x3f3f3f3f;
int Hashe[N];

int H(int x){
    return (x%N+N)%N;//因为有负数%后也是负数，所以+N)%N
    }
int find(int x){
    int ad=H(x);
    while(Hashe[ad]!=null && Hashe[ad]!=x){//从分配到的位置开始看是否空或者是否是自己
        ad++;
        if(ad==N)ad=0;  //闭环
    }
    return ad;
}


//10^5个数放10^5个位置，-10^9到10^9的范围靠 H(x%N),哈希函数解决，N取质数好，离2的幂尽可能远

int main (){
	int n,x;
	char a[2];
	memset(Hashe,null,sizeof(Hashe));  //每日一遍#include<string.h>
	scanf("%d",&n);
	for(int i=0;i<n;i++){
        scanf("%s%d",a,&x);
        if(*a=='I'){
            Hashe[find(x)]=x;
        }else if(*a=='Q'){
            if(Hashe[find(x)]==null)printf("No\n");//诶，你小子找到的地儿是空的嘞，你没来过
            else printf("Yes\n");
        }
    }
	
	return 0;
}

