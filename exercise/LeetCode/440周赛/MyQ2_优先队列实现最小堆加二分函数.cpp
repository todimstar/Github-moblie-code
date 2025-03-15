//time: 2025.03.10 9:48                    https://leetcode.cn/contest/weekly-contest-440/problems/choose-k-elements-with-maximum-sum/submissions/608340784/
#include <vector>
#include <queue>    //堆一般都被封装成优先队列，cpp是priority_queue<int,(vector<int>),(less<int>/greater<int>))//最大最小堆
#include <algorithm>// Java是PriorityQueue<Integer>，python是heapq
using namespace std;//像前k个元素、合并前k个链表都是堆的应用


class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> starts_pairs;

        for(int i=0;i<n;i++){
            starts_pairs.emplace_back(nums1[i],nums2[i]);
        }
        sort(starts_pairs.begin(),starts_pairs.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            return a.first<b.first;
        });

        vector<long long> prefix(n,0);//等下要用的妙妙工具，记录该位的最佳值
        priority_queue<int,vector<int>,greater<int>> q; //greater<int>表示最小堆,less<int>表示最大堆
        long long sum=0;
        for(int i=0;i<n;i++){
            int val = starts_pairs[i].second;
            if(q.size()<k){
                q.push(val);
                sum+=val;
            }
            else if(val>q.top()){
                sum-=q.top();
                q.pop();
                q.push(val);
                sum+=val;
            }prefix[i]=sum;//记录当前k个最大值
        }

        vector<long long> answer(n,0);//记得初始化全0，满足情况才改值
        for(int i=0;i<n;i++){
            int x = nums1[i];//要找的值
            auto it = lower_bound(starts_pairs.begin(),starts_pairs.end(),pair<int,int>(x,0),
                                    [](const pair<int,int>& a,const pair<int,int>& b){
                                        return a.first<b.first;
                                    });
            int index = it-starts_pairs.begin();//在starts_pairs里的index数字
            if(index-1>=0)answer[i] = prefix[index-1];//回答是预制体前缀的前一个k最大值
            //answer[i] = index>0 ? prefix[index-1]:0;
        }
        return answer;

    }
};