#include<iostream>	//算法注释：	，心得：	，题目网址：https://ac.nowcoder.com/acm/contest/93268/B
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e5+10;

int compare(const void* a,const void* b){
    return ((*(int*)a)-(*(int*)b));
}

void quick_sort(int* q,int l,int r){
	
	
}


int main (){
	int n,x;
	int a[100001];
	
	cin>>n>>x;

    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    
    qsort(a,n,sizeof(a[0]),compare);
    
    int minn=0,xm=x;
    for(int i=n-1;i>=0;i--){    //计算最少机子
        if(xm>0){
            xm-=a[i];
            minn++;
        }else break;
    }

    int maxn=0,xn=x;
    if(xn<=n){
        maxn=xn;
    }else{
        maxn = n;//每个拿一
        xn = xn%n;//看n份后剩下的
        /*for(int i=0;i<n;i++){    //计算最少机子
            if(xn>0 && a[i]>1){
                xn--;
                maxn++;
            }else if(a[i] == 1) continue;
            else break;
        }*/
    }
    cout<<minn<<" "<<maxn<<endl;
	
	return 0;
}
