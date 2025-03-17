// Date: 2025/03/17 20:23

#include <iostream>//算法注释：双指针，贪心  心得关键：想换到从后往前的[ 跟前往后的多的] 交换	   ，题目网址：https://leetcode-cn.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
#include <string>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int l=0,r=s.size()-1;
        int lcnt=0,rcnt=0,sum=0;
        while(l<r){
            while(s[r]!='[')r--;
            if(s[l]=='[')lcnt++;
            if(s[l]==']')rcnt++;
            if(lcnt<rcnt){
                lcnt++;
                rcnt--;
                r--;
                l++;
                sum++;
            }else{
                l++;
            }
        }
        return sum;
    }
};

// Main function for testing
int main() {
    Solution solution;
    
    // Test cases
    string test1 = "][";
    string test2 = "][][";
    string test3 = "]]][[[";
    
    cout << "Test 1: " << solution.minSwaps(test1) << endl;   // Expected: 1
    cout << "Test 2: " << solution.minSwaps(test2) << endl;   // Expected: 1
    cout << "Test 3: " << solution.minSwaps(test3) << endl;   // Expected: 2
    
    return 0;
}