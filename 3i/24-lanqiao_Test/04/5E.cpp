#include<iostream>	//算法注释：	题目网址：https://ac.nowcoder.com/acm/contest/97419/E
#include<stdlib.h>
#include<string>
#include<map>
#include<vector>

using namespace std;

const int N =1000+13;
typedef long long ll;
int n,k,T;
map<int,vector> grd;


int compare(const void* a,const void* b){
    return (((W*)a)->w-((W*)b)->w)?(((W*)a)->w-((W*)b)->w):(((W*)a)->v-((W*)b)->v);
}

ll solve(){
    ll sum=0;
    if(n>=grd.size()){//架子够装所有品牌瓶子
           
    }
}

int main (){

	int b,c;
    cin>>T;
	while(T--){

		scanf("%d %d",&n,&k);
        
		for(int i=0;i<k;i++){
            scanf("%d %d",&b,&c);
            grd[b].push_back(c);
        }
		
		printf("%d\n",solve());
	}

    
	return 0;
}
