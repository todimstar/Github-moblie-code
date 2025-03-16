#include<iostream>//03-16 18:32第二次尝试
#include<deque>
using namespace std;//重点是会问Ai了，看不懂就直说，直到他解释清楚

bool check(int k,string s){//队列的思想，记录每个翻转的终点，用count记录直到当前字符的翻转次数，类似窗口，公式为cur=(s[i]-'0'+count)%2
    int len=s.size();
    deque<int> q;
    int count=0;//记录直到当前字符的翻转次数

    for(int i=0;i<len;i++){//路过每个字符
        
        while(!q.empty() && q.front()<=i){//退出队列里已经路过的终点，减少他们占用的count
            q.pop_front();
            count--;
        }
        int cur=(s[i]-'0'+count)%2;

        if(!cur){
            if(i+k > len)return false;//直到最后一趴都没翻完
            count++;
            q.push_back(i+k);//添加终点
        }
    }
    
    return true;
}

int main(){

    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        
        for(int k=n;k>0;k--){
            if(check(k,s)){
                cout<<k<<endl;
                break;
            }
        }
    }
    return 0;
}