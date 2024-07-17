#include<iostream>
using namespace std;

const int N=1000;
int temp[N]; // 归并需要一个额外数组放排好的，归并结果在此数组

void merge_sort(int a[],int l,int r){
	if(l>=r)return;
	int mid=l+r>>1;
	merge_sort(a,l,mid);merge_sort(a,mid+1,r);  //左右递归建树，从个位开合并

	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r){ //左右归并
		if(a[i]<=a[j])temp[k++]=a[i++]; //当次函数临时借用temp数组存当前排好序的 //同时<=保证稳定性
		else temp[k++]=a[j++];
	}
	while(i<=mid)temp[k++]=a[i++];
	while(j<=r)temp[k++]=a[j++];

	for(i=0,j=l;i<k;i++,j++){ //只能i<k;  j啥都不懂
		a[j]=temp[i]; //归还当次函数使用的排好序的元素到a[]接着传下去
	}
}

int main (){
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    merge_sort(a,0,n-1);
    for(i=0;i<n;i++)printf("%d ",a[i]);

    return 0;
}