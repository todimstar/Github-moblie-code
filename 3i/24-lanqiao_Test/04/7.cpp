#include<iostream>	//算法注释：	题目网址：https://ac.nowcoder.com/acm/contest/97419/G
#include<stdlib.h>
#include<string>

using namespace std;

const int M =1000+13;
typedef long long ll;
int n,V;
struct W{
    int v,w,s;
};W w[M];

int compare(const void* a,const void* b){
    return (((W*)a)->w-((W*)b)->w)?(((W*)a)->w-((W*)b)->w):(((W*)a)->v-((W*)b)->v);
}

int solve(){
    int sumv=0,sumw=0;
    for(int i=0;i<n;i++){
        while(sumv+w[i].v<=V && w[i].s--){
            sumv += w[i].v;
            sumw += w[i].w;
            //cout<<i<<endl;
        }
    }return sumw;
}

int main (){

	
    scanf("%d%d",&n,&V);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&w[i].v,&w[i].w,&w[i].s);
    }
    qsort(w,n,sizeof(w[0]),compare);
    /*cout<<endl;
    for(int i=0;i<n;i++)printf("%d %d %d\n",w[i].v,w[i].w,w[i].s);
    */printf("%d\n",solve());

    
	return 0;
}
