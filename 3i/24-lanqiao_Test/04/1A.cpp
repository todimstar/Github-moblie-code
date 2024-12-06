#include<iostream>	//算法注释：贪心？，题目网址：https://ac.nowcoder.com/acm/contest/97419/A
#include<stdlib.h>
#include<string>

using namespace std;

const int N =200000+10;
typedef long long ll;
int T,n;
int a[N];

int compare(const void* a,const void* b){
    return ((*(int*)a)-(*(int*)b));
}

void solve(){
    int max1=0,max2=0,min1=0,min2=0,cntmax=0,cntmin=0;
    for(int i=n-1;i>3;i--){
        if(a[i]==a[i-1]){
            if(!cntmax)max1=a[i];
            else max2=a[i];
            cntmax++;
            i--;
            //cout<<"Max"<<i<<" "<<cntmax;
        }if(cntmax==2)break;
    }
    for(int i=0;i<n-5;i++){
        if(a[i]==a[i+1]){
            if(!cntmin)min1=a[i];
            else min2=a[i];
            i++;
            cntmin++;
            //cout<<"Min"<<i<<" "<<cntmin;
        }if(cntmin==2)break;
    }//cout<<"cntmax="<<cntmax<<" cntmin="<<cntmin<<endl;
    if(cntmax==2 && cntmin==2){
        cout<<"YES\n"<<min1<<" "<<min2<<" "<<min1<<" "<<max1<<" "<<max2<<' '<<min2<<' '<<max2<<' '<<max1<<endl;
    }else cout<<"NO"<<endl;
}

int main (){

	
	cin>>T;
	while(T--){

		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);

		qsort(a,n,sizeof(a[0]),compare);
		//for(int i=0;i<n;i++)printf("%d ",a[i]);
		solve();

	}
	
	return 0;
}
