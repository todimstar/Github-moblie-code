#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N =1010;

struct pd{
	int first;
	int* second;
	int second_nums=0;
};
pd arr[N];

long long n = 0, m = 0;

int fi(int x){//找到arr对应下标 
	
	
	for(int i =0;i<n;i++){
		if(arr[i].first == x){//发现x
			return i;
			
		}
	}return -1;
}
/*int findjg (vector<int>* jg,int x){
	for(size_t i=0;i < jg->size();i++){
		if(jg[i] == x){
			return i;
		}
	}return -1;//一直没有找到 
}*/

void dfs(vector<int>* jg,int x){

	int havi=-1,havt;
	
	havi = fi(x);
	if(havi == -1){//该x没找到
		//if(findjg(jg,x) == -1)//没有见过的 
		if(std::find(jg->begin(),jg->end(),x) == jg->end())
			jg->push_back(x);//进
			return;
	}
	else{
		 
		for(int j=0;j< arr[havi].second_nums;j++){
			havt = fi(arr[havi].second[j]);
			if(havt!=-1){//如果存在arr里 
				dfs(jg,arr[havi].second[j]);//进去找
			}else{
				//if(findjg(jg,arr[havi].second[j]) == -1)//也是没有见过的 
				if(find(jg->begin(),jg->end(),arr[havi].second[j]) == jg->end())
					jg->push_back(arr[havi].second[j]);
			}
		}


	}

}

int main()
{


	cin >> n>>m;
	
	
	for (int i = 0; i < n; i++)
	{
		
		int t;
		cin>>t;
		cin>>arr[i].first;
		int* a = new int[t];
		arr[i].second = a;
		arr[i].second_nums = t;
		for(int i=0;i<t;i++){
			cin>>a[i];
		}
	}
		
	for (int i = 0; i < m; i++)
	{
		int x;
		cin>>x;
		
		if(fi(x) == -1){//首次没找到，为定理
			if(i != m-1)cout<<0<<endl;
			else cout<<0;
			continue;
		}	
		else {
			vector<int> jg;
			
			dfs(&jg,x);
			if(i != m-1)cout<<jg.size()<<endl;
			else cout<<jg.size();
		}
		
	}
	
	return 0;

}