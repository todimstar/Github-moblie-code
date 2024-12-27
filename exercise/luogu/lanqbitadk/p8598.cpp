#include<iostream>	//算法注释：模拟	，心得：要快	，题目网址：
#include<algorithm>
#include<string>
#include<sstream>

using namespace std;

const int N =1e5+13;
typedef long long ll;
int T;
int a[N],num;

int m,n;

int main (){
    cin>>T;
    while(cin>>num)a[num]++;
    for(int i=1;i<=1e5;i++){
        if(a[i-1]&&a[i+1]&&!a[i])m=i;
        if(a[i]>1)n=i;
        if(m&&n)break;
    }cout<<m<<" "<<n<<endl;
    return 0;
}

/*int main (){
	int id,size=0;
	scanf("%d",&T);
	getchar();
	while(T--){
        string line;
        getline(cin,line);
        //cout<<line;
        istringstream is(line);
        while(is>>id){
            a[size++]=id;
        }
    }
    sort(a,a+size);
    for(int i=0;i<size;i++)cout<<a[i]<<" ";
    cout<<endl;
    //int num=nmap.begin()->first-1;
    for(int i=1;i<size;i++){
        //cout<<i.first<<" "<<i.second<<endl;
        if(a[i]==a[i-1]){
            m=a[i];
        }
        if(a[i-1]+2<=a[i]){
            n=a[i]-1;
        }
    }
    cout<<n<<" "<<m<<endl;
	return 0;
}*/
