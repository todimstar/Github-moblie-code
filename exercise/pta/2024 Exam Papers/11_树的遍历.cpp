#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> tree(1e5+13);//树
vector<int> line;//rank,order
int maxd=0;
bool flag=true;

void dfs(int index){
    if(index!=0 && !tree[index].empty()){//0次是确定根节点的，不算;叶节点也不算
        if(!maxd)maxd=tree[index].size();
        if(tree[index].size()!=maxd)flag=false;//但是遍历不能停
    }
    
    for(int i:tree[index]){
        line.push_back(i);
        dfs(i);
    }
}

int main (){
    int n;
    cin>>n;
    int t;
    
    for(int i=1;i<=n;i++){//元素1为根节点，挂在0下
        cin>>t;
        tree[t].push_back(i);//入父节点名下
    }
    dfs(0);
    
    cout<<maxd<<" ";
    if(flag) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    
    int len=line.size();
    for(int i=0;i<len;i++){
        cout<<line[i];
        if(i<len-1)cout<<' ';
    }
    return 0;
}