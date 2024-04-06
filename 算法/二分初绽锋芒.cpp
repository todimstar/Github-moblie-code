#include<iostream>
#include<stdlib.h>
using namespace std;

struct xy{
    int x,y;
};

int compare(const void* a,const void* b){
    return (*(int*)a-*(int*)b);
}

int erfenb(const int* a,int n,const int x,const int y){
	int l=0,r=n;
	int midx,midy;
	/// 左边界 
	while(l<r){
		midx=(l+r)/2; //midx=l+(r-l)/2;
		if(a[midx]==x)r=midx;
		else if(a[midx]<x)l=midx+1;
		else if(a[midx]>x)r=midx;
	}midx=l;
	// 右边界 
	l=0;r=n;
	while(l<r){
		midy=(l+r)/2;
		if(a[midy]==y)l=midy+1;
		else if(a[midy]<y)l=midy+1;
		else if(a[midy]>y)r=midy;
	}midy=l-1;
	return midy-midx+1;
}


int erfena(const int* a,int n,const int x,const int y){
    int l=0,r=n-1;
    int midx,midy;
    bool xx=false,yy=false;
    // 对于数组中有x能查到的二分
    while(l<=r){// l=r也能查到
        midx=l+(r-l)/2;//  避免r+l溢出int范围
        if(a[midx]==x){
            if(midx-1>=0&&a[midx-1]==x){// 防越下界 
                while(midx-1>=0&&a[--midx]==x);
            }xx=true;break;
        }
        else if(a[midx]>x)r=midx-1;
        else if(a[midx]<x)l=midx+1;//+1-1是为了跳过已搜查的mid
    }
	if(a[midx]>x)xx=true;
	l=0;r=n-1;
    while(l<=r){
        midy=l+(r-l)/2;
        if(a[midy]==y){
            if(midy+1<=n-1&&a[midy+1]==y){// 防越上界 
                while(midy+1<=n-1&&a[++midy]==y);
            }yy=true;break;
        }
        else if(a[midy]>y)r=midy-1;
        else if(a[midy]<y)l=midy+1;
    }
	if(a[midy]<y)yy=true; 
	
	if(xx&&yy){
        return midy-midx+1;
    }return -1;
}

int main (){
    int m=(3/2);
    cout<<m;
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];
    int q;
    cin>>q;
    xy feng[q];
    for(i=0;i<q;i++){
        cin>>feng[i].x>>feng[i].y;
    }
    qsort(a,n,sizeof(a[0]),compare);
    for(i=0;i<q;i++){
        cout<<erfenb(a,n,feng[i].x,feng[i].y)<<endl;
    }
    return 0;
}
