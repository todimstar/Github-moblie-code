#include<iostream>	
#include<stdlib.h>
#include<math.h>

using namespace std;

const int N =1e5+10;
int a[N];

int compare(const void* a,const void* b){
    return ((*(int*)a)-(*(int*)b));
}


int main (){
	int T,max=0;
	
	cin>>T;
		
    for(int i=0;i<T;i++)scanf("%d",&a[i]);

    qsort(a,T,sizeof(a[0]),compare);

    for(int i=T-1;i>=0;i--){
        if(sqrt(a[i])!=(int)sqrt(a[i])){
            max=a[i];
            break;
        }
    }
    cout<<max;
	
	return 0;
}
