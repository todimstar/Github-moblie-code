#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>

using namespace std;
#define MAXSIZE 100 // 定义名字的字符数

typedef struct val {
    char childname[MAXSIZE]; // 节点中的孩子名
    struct val* next;
} val;//child节点 

typedef struct {
    char nodename[MAXSIZE];
    val* first;
} node;//链表头节点 

typedef struct {
    int size;
    node* nodes;
} tree;//家族树 

void inittree(tree* t) //初始化邻接链表 
{
    printf("请输入族谱人数: \n");
    scanf("%d", &t->size);
    t->nodes = (node*)malloc(sizeof(node) * t->size); // 给node开出t->size个空间
    int i;
    printf("请输入测试用例\n");
    for (i = 0; i < t->size; ++i) {
        t->nodes[i].first = NULL; // 将first指针置为空
        scanf("%s", t->nodes[i].nodename); // 传入nodename
        int j, childrenCount;
        scanf("%d", &childrenCount);
        val* cur = NULL;
        for (j = 0; j < childrenCount; ++j) {
            val* newChild = (val*)malloc(sizeof(val));
            scanf("%s", newChild->childname);
            newChild->next = NULL;
            if (cur == NULL) {
                t->nodes[i].first = newChild;
            } else {
                cur->next = newChild;
            }
            cur = newChild;
        }
    }
}

void displaytree(tree* t)//显示领接链表的族谱树 
{
    int i;
    for (i = 0; i < t->size; ++i) {
        val* cur = t->nodes[i].first;
        if (cur != NULL) {
            printf("%s的孩子有：", t->nodes[i].nodename);
            while (cur) {
                printf("%s\t", cur->childname);
                cur = cur->next;
            }
            printf("\n");
        }
    }
}

int findnodeindex(tree* t) //替换查找名字信息为表头下标 
{
    printf("请输入要查找后代的人名\n");
    char indexname[MAXSIZE];
    scanf("%s", indexname);
    for (int j = 0; j < t->size; ++j) {
        if (strcmp(indexname, t->nodes[j].nodename) == 0) {
            return j;
        }
    }
    return -1; // 未找到返回-1
}


void printchildname(tree* t, int index)//深度优先算法递归输出childname 
{
    
    int visited[t->size]; // 用来记录查找过的后代
    for (int i = 0; i < t->size; ++i) 
    {
        visited[i] = 0; // 初始化 visited 数组为 0
    }
    val* cur = t->nodes[index].first;
    if (cur == NULL) 
    {
        return ;
    }
    while (cur != NULL) 
    {
        printf("%s\t", cur->childname);
        int j;
        for (j = 0; j < t->size; ++j) 
        {
            if (strcmp(cur->childname, t->nodes[j].nodename) == 0)
            {
                break;
            }
        }
        if (j < t->size) 
        {
            if (visited[j] == 0) {
                visited[j] = 1; // 标记该节点为已访问
                printchildname(t, j);
            }
        }
        cur = cur->next; // 继续遍历下一位孩子
    }
}

int countchildnum(tree* t,int index,int &count) //用int函数返回计数孩子数 
{
    
    val* cur = t->nodes[index].first ;
    if(cur == NULL)
    {
    	
	        return 0;
	    } 		
    while(cur != NULL)
    {
        int j;
        for(j=0; j < t->size; ++j)
        {
            if(strcmp(cur->childname,t->nodes[j].nodename)==0)
            {
                break;
            }
        } 
        if(j < t->size)
        {
        	count++;
            countchildnum(t, j,count);
        }
        cur=cur->next;
    }
    return 1; 
} 

void answer(tree* t, int index, int num) //设计回答 
{
    printf("\n要查找的%s的子孙数是%d\n", t->nodes[index].nodename, num);
    return;
}

void freetree(tree* t) //释放领接链表的空间 
{
    for (int i = 0; i < t->size; ++i) 
    {
        val* cur = t->nodes[i].first;
        while (cur != NULL) 
        {
            val* temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
    free(t->nodes);
}

int main() {
    tree t;
    inittree(&t);
    displaytree(&t);
    int index = findnodeindex(&t);
    if (index != -1) 
    {
        printf("该人的后代有: \n");
        printchildname(&t, index);
    } 
    else 
    {
        printf("未找到要查找的人\n");
    }
    int num=0;
	cout<<"test="<<countchildnum(&t,index,num);
	
    answer(&t,index,num);
    freetree(&t);
    return 0;
}
