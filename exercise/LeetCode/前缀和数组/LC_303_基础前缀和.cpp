#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> sumnums;
    
    NumArray(vector<int>& nums) {
        int len = nums.size();
        sumnums = vector<int>(len+1,0); //left可能要退1，前缀和数组便要预留边界0

        for(int i=1;i<=len;i++){
            sumnums[i]=sumnums[i-1]+nums[i-1]; //天，别忘记前缀和的本质，要自增上去
        }
        //for(int i:sumnums)cout<<i<<" ";
    }
    
    int sumRange(int left, int right) {
        return sumnums[right+1]-sumnums[left]; //有错位记得
    }
};
/*
优点：
    预处理时间为O(n)，查询时间为O(1)
    额外空间复杂度为O(n)

其他解法：
    线段树/线段数组解法:
    时间复杂度：预处理O(n)，查询O(logn)
    空间复杂度：O(n)
    差距：实现复杂，对于此题过于繁重
    优势：可以处理数组修改的情况（LC_307）
*/

int main() {
    // 测试用例1
    vector<int> nums1 = {-2, 0, 3, -5, 2, -1};
    NumArray numArray1(nums1);
    
    cout << "测试用例1:" << endl;
    cout << "sumRange(0, 2) = " << numArray1.sumRange(0, 2) 
         << ", 期望值: 1" << endl;
    cout << "sumRange(2, 5) = " << numArray1.sumRange(2, 5) 
         << ", 期望值: -1" << endl;
    cout << "sumRange(0, 5) = " << numArray1.sumRange(0, 5) 
         << ", 期望值: -3" << endl;
    
    // 测试用例2
    vector<int> nums2 = {1, 2, 3, 4};
    NumArray numArray2(nums2);
    
    cout << "\n测试用例2:" << endl;
    cout << "sumRange(0, 1) = " << numArray2.sumRange(0, 1) 
         << ", 期望值: 3" << endl;
    cout << "sumRange(1, 2) = " << numArray2.sumRange(1, 2) 
         << ", 期望值: 5" << endl;
    
    return 0;
}