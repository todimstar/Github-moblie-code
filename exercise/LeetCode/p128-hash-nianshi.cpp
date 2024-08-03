//原地址：https://leetcode.cn/problems/longest-consecutive-sequence/solutions/1176496/xiao-bai-lang-ha-xi-ji-he-ha-xi-biao-don-j5a2/
//写完回想起来，还可以双指针法，即快慢迭代器，之前想过，但写题隔了一天忘了,但更麻烦，不如一起手搓哈希,兄弟


//acwing手搓哈希，虽然不够进阶方法，但简单快速

/*const int N=1e5+1e5+3,null=0x3f3f3f3f;
class Solution {
private:
int H[N];

int find(int x){
    int ad=(x%N+N)%N;
    while(H[ad]!=null && H[ad]!=x){
        ad++;
        if(ad==N)ad=0;
    }return ad;
}

public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        memset(H,0x3f,sizeof(H));
        for(auto i:nums){
            H[find(i)]=i;
        }
        int maxlength=1;
        
        for(auto i:nums){
            int t=i,cnt=1;
            if(H[find(t-1)]==null){
                while(H[find(++t)]!=null)cnt++;
            }maxlength=max(maxlength,cnt);
        }
        return maxlength;
    }
};*/



//类acwing手搓哈希方法，但用unordered_map实现

/*const int N=1e5+1e5+3;
class Solution {

public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        unordered_map <int,bool>m;  //破unordered_map容器um，不有序，滚啊，超时就超了烦死

        for(int i=0;i<nums.size();i++){
            m[nums[i]]=true;
        }int maxlength=1;
        
        for(int i=0;i<nums.size();i++){
            int t=nums[i],cnt=1;
            if(!m.count(t-1)){
                while(m.count(++t))cnt++;
            }
            maxlength=max(maxlength,cnt);
        }
        
        return maxlength;
    }
};*/




//不符合题意的不快速方法：
//----------------------用map能过的方式，即不用count()方法，但要手动动迭代器
//----------------------且，理论上讲应该不是O(n)，起码O(nlogn)应该用了map自动耗时nlogn
//----------------------且这方法unordered_map走不了因为没排序，但排序就没意思了
#include<iostream>
#include<map>
#include<vector>
//#include<algorithm>

using namespace std;

//const int N=2000000002;
class Solution {

public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        map <int,bool>m;  //破unordered_map容器um，不有序，滚啊，超时就超了烦死
        
        /*for (int i=0;i<nums.size();i++) {
            hashe[nums[i]] = true;
        }*/
        for(auto i : nums){m[i]=true;}//完全可以这样插入，不能少不然就是空的um了

        int length=1,maxlength=1;   //用了map要length初始化1，且，只要有一个maxlength就至少为1
        cout<<"m=";
        for(auto i=m.begin();i!=m.end();++i)cout<<i->first<<" ";
        cout<<endl;
        for(auto i=m.begin();i!=m.end();++i){
            cout<<"i->first="<<i->first<<endl;
            auto inext=next(i);
            if(inext==m.end())break;   //这瓜玩意没有逆向只有next()好吧将就着用了
            if((1+(i->first) == inext->first) ){
                length++;
                cout<<i->first<<endl;
            }
            else length=1;
            maxlength=max(maxlength,length);
        }
            
        
        return maxlength;
    }
};

int main (){
    Solution solution;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "The length of the longest consecutive sequence is: " << solution.longestConsecutive(nums) << endl;
    return 0;
}