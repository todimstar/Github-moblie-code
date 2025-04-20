#include <iostream>
#include <set>
using namespace std;
int main() {
    int n, t;
    cin >> n;
    set<int> s;
    s.insert(0);//初个元素，为了循环的*rbegin()，之后输出需要size()-1
    for(int i=0;i<n;i++){
        cin>>t;
        if(t<*s.rbegin()){//可以加入已有队伍尾
            s.erase(*(s.upper_bound(t)));
        }
        s.insert(t);//要是没有if就是新加，要是有if，那也会重排序，帅
    }
    cout<<s.size()-1;
    return 0;
}