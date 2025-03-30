#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        long long max_=0,jg;
        int maxi=0,len=nums.size();
        for(int i=0;i<len;i++){
            if(max_<nums[i]){
                max_=nums[i];
                maxi=i;
            }
        }
        max_<<=k;//左移k位实现，蛐蛐32+15不会爆Longlong的64

        if(maxi){//不是0位
            long long sum=nums[0];
            for(int i=1;i<len;i++){
                if(i==maxi){
                    sum |= max_;
                }else{
                    sum |= nums[i];
                }
            }jg=sum;
        }else{
            // 第0位是最大值的情况
            long long sum = max_;
            for(int i=1; i<len; i++){
                sum |= nums[i];
            }
            jg = sum;
        }
        return jg;
    }
};

// 测试函数
void runTest(vector<int>& nums, int k, long long expected) {
    Solution sol;
    long long result = sol.maximumOr(nums, k);
    
    cout << "输入: nums = [";
    for(size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if(i < nums.size() - 1) cout << ",";
    }
    cout << "], k = " << k << endl;
    
    cout << "输出: " << result << endl;
    cout << "预期: " << expected << endl;
    cout << "结果: " << (result == expected ? "正确" : "错误") << endl;
    cout << "------------------------" << endl;
}

int main() {
    // 测试用例1
    vector<int> nums1 = {12, 9};
    int k1 = 1;
    runTest(nums1, k1, 30);  // 预期输出: 30
    
    // 测试用例2
    vector<int> nums2 = {8, 1, 2};
    int k2 = 2;
    runTest(nums2, k2, 35);  // 预期输出: 35
    
    // 测试用例3
    vector<int> nums3 = {10, 8, 4, 7};
    int k3 = 2;
    runTest(nums3, k3, 47);  // 预期输出: 47
    
    return 0;
}