/*
给你两个整数数组，nums1 和 nums2，长度均为 n，以及一个正整数 k 。

对从 0 到 n - 1 每个下标 i ，执行下述操作：

找出所有满足 nums1[j] 小于 nums1[i] 的下标 j 。
从这些下标对应的 nums2[j] 中选出 至多 k 个，并 最大化 这些值的总和作为结果。
返回一个长度为 n 的数组 answer ，其中 answer[i] 表示对应下标 i 的结果。

 

示例 1：

输入：nums1 = [4,2,1,5,3], nums2 = [10,20,30,40,50], k = 2

输出：[80,30,0,80,50]

解释：

对于 i = 0 ：满足 nums1[j] < nums1[0] 的下标为 [1, 2, 4] ，选出其中值最大的两个，结果为 50 + 30 = 80 。
对于 i = 1 ：满足 nums1[j] < nums1[1] 的下标为 [2] ，只能选择这个值，结果为 30 。
对于 i = 2 ：不存在满足 nums1[j] < nums1[2] 的下标，结果为 0 。
对于 i = 3 ：满足 nums1[j] < nums1[3] 的下标为 [0, 1, 2, 4] ，选出其中值最大的两个，结果为 50 + 30 = 80 。
对于 i = 4 ：满足 nums1[j] < nums1[4] 的下标为 [1, 2] ，选出其中值最大的两个，结果为 30 + 20 = 50 。
示例 2：

输入：nums1 = [2,2,2,2], nums2 = [3,1,2,3], k = 1

输出：[0,0,0,0]

解释：由于 nums1 中的所有元素相等，不存在满足条件 nums1[j] < nums1[i]，所有位置的结果都是 0 。

 

提示：

n == nums1.length == nums2.length
1 <= n <= 105
1 <= nums1[i], nums2[i] <= 106
1 <= k <= n
*/

////time: 2025.03.09 23:34                    https://leetcode.cn/contest/weekly-contest-440/problems/choose-k-elements-with-maximum-sum/submissions/608340784/
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> sorted_pairs;
        // 1. 将nums1和nums2组合并排序
        for (int i = 0; i < n; ++i) {
            sorted_pairs.emplace_back(nums1[i], nums2[i]);
        }
        sort(sorted_pairs.begin(), sorted_pairs.end());

        // 2. 用最小堆维护前k大值，并计算前缀和
        vector<long long> prefix(n, 0);
        priority_queue<int, vector<int>, greater<int>> min_heap; // 优先队列实现最小堆
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            int val = sorted_pairs[i].second;
            if (min_heap.size() < k) {
                min_heap.push(val);
                sum += val;
            } else if (val > min_heap.top()) { // 新值比堆顶大，替换
                sum -= min_heap.top();
                min_heap.pop();
                min_heap.push(val);
                sum += val;
            }
            prefix[i] = sum; // 记录当前位置的前缀和
        }

        // 3. 对每个元素用二分查找确定答案
        vector<long long> answer(n, 0);
        for (int i = 0; i < n; ++i) {
            int x = nums1[i];
            // 找到第一个≥x的位置
            auto it = lower_bound(sorted_pairs.begin(), sorted_pairs.end(), make_pair(x, 0),     //或者 pair<int, int>(x, 0)
                                    [](const pair<int, int>& a, const pair<int, int>& b) {
                                        return a.first < b.first;
                                    });
            int pos = it - sorted_pairs.begin();
            if (pos > 0) {
                answer[i] = prefix[pos - 1];
            }//answer[i] = (pos>0)?prefix[pos-1]:0;
        }
        return answer;
    }
};