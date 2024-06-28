#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

bool st[10]={0};// 全false
int num[10];// 1~9
int cot=0;

int load(int l,int r,const int a[]){
    int f=0;
    for(;l<=r;l++){
        f=f*10+a[l];
    }
    return f;
}

void dfs(int u){
    if(u>9){
        int a=load(1,4,num),b1=num[5],b2=num[5]*10+num[6];
        int c1=load(6,9,num),c2=load(7,9,num);
        if(a==b1*c1)cout <<a<<" = "<< b1<<" x "<< c1<<"\n\n\n\n"<< endl;
		if(a==b2*c2)cout <<a<<" = "<< b2<<" x "<< c2<<"\n\n\n\n"<< endl;
        printf("%d=%d*%d\n%d=%d*%d??\n",a,b1,c1,a,b2,c2);
        return ;
    }else{
        for(int i=1;i<10;i++){
            if(!st[i]){
                st[i]=true;
                num[u]=i;
                dfs(u+1);
                st[i]=false;
            }
        }
    }
}

int main (){
	
	dfs(1);
	cout<<cot;
    return 0;
}
