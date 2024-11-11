#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

const int N =1e5+13;
typedef pair<int,int> PII;
vector<PII> v;



int main (){
	int n,k,t1,t2;
	
	cin>>n;
	for(int i=0;i<n;i++){
        scanf("%d",&k);
        if(k>1){
            cin>>t1>>t2;
            v.push_back({t1,t2});
        }else{
            cin>>t1;
            v.push_back({t1,-1});
        }
	}
    vector<int> m(n+1);
    for(int i=0;i<n;i++){
        if(find(m.begin(),m.end(),v[i].first) == m.end()){//1不重复可以进
            m[i] = v[i].first;
        }else if(v[i].second != -1 && find(m.begin(),m.end(),v[i].second) == m.end()){//存在second且也不重复
            m[i] = v[i].second;
        }else{//否则一二都重复
            cout<<"kou is angry";
            return 0;
        }
    }
    for(int i=0;i<n;i++)cout<<m[i]<<" ";
	
	return 0;
}
