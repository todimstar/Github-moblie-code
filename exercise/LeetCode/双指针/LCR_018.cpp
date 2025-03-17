```
time: 2025-03-08 20:40~21:40    https://leetcode.cn/problems/XltzEq/submissions/
```
#include <iostream>//算法注释：双指针	，心得：排除异常后，首尾指针向中遍历最为快捷，isalnum()、tolower()、toupper()有点用	，题目网址：https://leetcode.cn/problems/XltzEq/submissions/607883157/
#include <string>
#include <vector>//优化思路：可以在判断前提前处理好字符串，但会增加空间复杂度
#include <stack>
using namespace std;

class Solution {
public:
//--------------------------双指针秒了系列--------------------------
    bool isPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r){//检查字母的循环
            //跳过所有非数字非字母字符
            while(l<r && !isalnum(s[l])){//isalnum()判断是否是字母或数字 
                l++;
            }
            while(l<r && !isalnum(s[r])){
                r--;
            }
            //既然是回文，敢不敢去了数字对字母，对得上就是好汉
            if(tolower(s[l]) != tolower(s[r])){ //tolower()转换为小写,toupper()转换为大写
                return false;//内鬼被抓了
            }
            //能活到这的l和r都已受阅
            l++;
            r--;
        }
        return true;
    }
};
//------------------------------
/*
    bool isPalindrome(string s) {
        bool flag = true;
        int len = s.size();
        if(len!=1){
            vector<char> chuan;//去除无关字符
            for(int i=0;i<len;i++){
                if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9'){
                    chuan.push_back(s[i]);
                }
            }

            std::stack<char> st;
            len=chuan.size();
            if(!len)return true;//空字符串
            int len2=len/2;//奇数需要跳中间一位
            
            //记录前半段st
            for(int i=0;i<len2;i++){
                    st.push(tolower(chuan[i]));
            }
            int start=len2;
            if(len&1){//奇数ture,偶数false
                start++;
            }
            for(;start<len;start++){
                if(tolower(chuan[start]) != st.top()){
                    flag=false;
                    break;
                }st.pop();
            }
        }
        else{
            flag = true;
        }
        return flag;

    }
};
*/

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