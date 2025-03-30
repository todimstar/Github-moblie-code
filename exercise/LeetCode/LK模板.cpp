//time: 2025.03.05 23:24                    https://leetcode.cn/problems/range-sum-query-immutable/description/
#include <iostream>//算法注释：	，心得：	，题目网址：
#include <string>
#include <vector>
#include <stack>
/*
补全提示词:
这题变成完整样式，
并指出跟我相比最便捷有效的一个或几个思路的差别
Claude3.7：
帮我把这题力扣变成完整样式，但是不要动我的主代码，就帮我补全以便我本地运行和测试

总结提示词：
你看我这题总结得如何？
还有什么要补充的知识点吗？正在速通算法，1个月后打比赛
*/
using namespace std;

class Solution {
public:
//--------------------------XXXX系列--------------------------
    bool isPalindrome(string s) {
        
    }
};
//------------------------------


// 测试函数
void runTest(Solution& sol, const string& testCase, bool expected) {
    bool result = sol.isPalindrome(testCase);
    cout << "输入: \"" << testCase << "\"" << endl;
    cout << "输出: " << (result ? "true" : "false") << endl;
    cout << "预期: " << (expected ? "true" : "false") << endl;
    cout << "结果: " << (result == expected ? "通过" : "失败") << endl;
    cout << "------------------------" << endl;
}

int main() {
    Solution solution;
    
    // 测试用例
    runTest(solution, "A man, a plan, a canal: Panama", true);
    runTest(solution, "race a car", false);
    runTest(solution, " ", true);
    runTest(solution, "0P", false);
    runTest(solution, "a", true);
    
    // 你可以添加更多测试用例
    
    // 允许用户输入自定义测试用例
    string userInput;
    cout << "请输入自定义测试字符串 (输入'exit'退出): ";
    while (getline(cin, userInput) && userInput != "exit") {
        bool result = solution.isPalindrome(userInput);
        cout << "结果: " << (result ? "是回文" : "不是回文") << endl;
        cout << "请输入自定义测试字符串 (输入'exit'退出): ";
    }
    
    return 0;
}