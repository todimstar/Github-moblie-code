//time:2025.03.09 00:30 自解，第二天ai精妙解法          https://leetcode.cn/problems/product-of-array-except-self/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
//----------------精妙前缀和*后缀和出除自身以外的乘积----------------
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        
        // 计算前缀积
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix; //answer[i]存储的是i左边的前缀和
            prefix *= nums[i];
        }
        
        // 计算后缀积并与前缀积相乘
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;    //answer[i]再*右边的后缀和，便可得到除自身以外的乘积
            suffix *= nums[i];
        }
        
        return answer;
    }

//----------------暴力大法----------------
/*    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        bool zero = false;  // 标记是否有一个0
        bool zero2 = false; // 标记是否有两个及以上的0
        bool one = false;   // 标记是否有非0数字
        int sum = 1;        // 所有非0数字的乘积
        
        // 遍历计算乘积并标记0的情况
        for(int i:nums){
            if(i){
                one = true;
                sum*=i;     // 保留无0和
            }
            else if(!zero){ // 记录0标记
                zero=true;
            }else{
                zero2=true;
            }
        }
        
        if(!one) sum=0;
        
        // 构建结果数组
        for(int i:nums){
            if(i && !zero) answer.push_back(sum/i);     // 整队没有0
            else if(!i && !zero2) answer.push_back(sum); // i是0且没有竞争对手0
            else answer.push_back(0);                    // 整队有多个0，其余都是0
        }
        return answer;
    }*/
//------------------------------
};

// 测试函数
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    // 测试用例1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = sol.productExceptSelf(nums1);
    cout << "输入: [1, 2, 3, 4]" << endl;
    cout << "输出: ";
    printVector(result1);
    cout << "预期: [24, 12, 8, 6]" << endl << endl;
    
    // 测试用例2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> result2 = sol.productExceptSelf(nums2);
    cout << "输入: [-1, 1, 0, -3, 3]" << endl;
    cout << "输出: ";
    printVector(result2);
    cout << "预期: [0, 0, 9, 0, 0]" << endl;
    
    return 0;
}