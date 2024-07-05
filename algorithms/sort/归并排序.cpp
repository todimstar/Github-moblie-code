#include<iostream>
using namespace std;

const int N=1000;
int temp[N];
void merge_sort(int a[],int l,int r){
	if(l>=r)return;
	int mid=l+r>>1;
	merge_sort(a,l,mid);merge_sort(a,mid+1,r);

	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j])temp[k++]=a[i++];
		else temp[k++]=a[j++];
	}
	while(i<=mid)temp[k++]=a[i++];
	while(j<=r)temp[k++]=a[j++];

	for(i=0,j=l;i<k;i++,j++){
		a[j]=temp[i];
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