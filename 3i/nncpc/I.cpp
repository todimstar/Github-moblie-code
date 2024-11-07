#include<iostream>	//算法注释：滑动窗口应用	，心得：看破	，题目网址：https://csexam.gxu.edu.cn/team/problems/109/text
#include<stdlib.h>//I题输出样例为:3813
#include<string>

using namespace std;

const int N =1e6+10;
int a[N];
int n,k;

long long hua(){
    long long sum=0,max=0;
    if(k!=0){
        
        for(int i=0;i<=k;i++){//k=1时就是拿两个
            sum+=a[i];
        }max = sum;
        for(int i=k;i<n;i++){
            sum -= a[i-k];  //删前
            sum += a[i+1];  //加后
            max = sum>max?sum:max;
        }
    }else{
        for(int i=0;i<n;i++)max = max<a[i]?a[i]:max;    //k=0拿max
    }
    return max;
}


int main (){


	
	cin>>n>>k;
	
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    
    //qsort(a,n,sizeof(a[0]),compare);
    cout<<hua();

	
	return 0;
}
