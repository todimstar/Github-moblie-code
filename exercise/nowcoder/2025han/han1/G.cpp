#include<iostream>	//算法注释：	，心得：	，题目网址：https://ac.nowcoder.com/acm/contest/95323/G
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

const int N =1e9+13;
typedef long long ll;
int n;
ll sum,cnt;


int main (){
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        //cout<<"a["<<i<<"] = "<<a[i]<<", "<<endl;
    }
    if(sum == (n+1)*n/2){
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            cnt+=abs(a[i]-i-1);
            //cout<<"a["<<i<<"] = "<<a[i]<<", "<<"i+1 = "<<i+1<<" abs(a[i]-i-1)="<<abs(a[i]-i-1)<<endl;
        }cout<<cnt/2<<endl;
    }else{
        cout<<-1<<endl;
    }
	
	return 0;
}
