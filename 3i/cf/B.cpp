#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

typedef long long ll;
const int N =2000+10;
int T,n;
ll a[N];

int compare(const void* a,const void* b){
    if((*(ll*)a)>(*(ll*)b))return 1;
    else if((*(ll*)a) == (*(ll*)b))return 0;
    else if((*(ll*)a) < (*(ll*)b))return -1;
}

bool pd(ll cha){//判断差值为k时，满不满足从后往前找两两差值都在k内，o(n),成功意味着可以缩小
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(a[i+1] - a[i]>cha){//允许一次超出
            cnt++;
            if(cnt>1)return false;//多了就寄
        }
    }return true;
}


int main (){

	
	cin>>T;
	while(T--){

		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		
		qsort(a,n,sizeof(a[0]),compare);

		ll l = 1, r = 1e18,mid = (r-l)/2+l;
        while(l<r){
            mid = (r-l)/2+l;
            if(pd(mid)){
                r=mid;
            }else{
                l=l+1;
            }
        }
		
		cout<<l<<endl;

	}
	
	return 0;
}
