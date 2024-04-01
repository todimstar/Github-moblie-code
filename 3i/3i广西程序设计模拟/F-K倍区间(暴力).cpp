#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100010


int main (){
	int n,k,i,j;
    scanf("%d %d",&n,&k);
    int a[n],sum,cot=0;
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++){sum=a[i];
        if(sum%k==0)cot++;
        for(j=i+1;j<n;j++){
            sum+=a[j];
            if(sum%k==0)cot++;
        }
    }printf("%d",cot);
	return 0;
}
