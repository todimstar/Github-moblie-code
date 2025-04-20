#include <string>
#include <map>
#include <algorithm> // 需要包含 <algorithm> 头文件以使用 rbegin() 和 rend()

using namespace std; // 建议添加，或者在代码中使用 std:: 前缀

class Solution {
public:
    string smallestPalindrome(string s) {
        // 如果字符串长度小于等于1，它本身就是回文，直接返回
        if(s.size() <= 1){ // 修改为 <= 1 更严谨
            return s;
        }

        // 使用 map 统计每个字符出现的次数
        map<char,int> hash;
        for(char ch : s){
            hash[ch]++;
        }

        string jg; // 用于存储回文串的前半部分（以及可能的中间字符）
        bool flag = false; // 标记是否存在出现奇数次的字符
        char ch = '\0'; // 存储出现奇数次的那个字符，初始化为空字符

        // 遍历 map（map 会按键的字典序自动排序，保证了结果是最小的）
        for(auto const& [key, val] : hash){ // 使用结构化绑定，更现代的 C++ 写法
            // 如果当前字符出现次数为奇数
            if(val % 2 != 0){
                // 如果之前已经发现了一个奇数次字符，说明无法构成回文（题目保证输入可以构成回文，这里可以省略检查，但加上更健壮）
                // if(flag) { /* 处理无法构成回文的情况，例如返回空字符串或抛出异常 */ }
                flag = true; // 标记找到了奇数次字符
                ch = key;    // 记录这个字符，它将是回文串的中心
            }
            // 将当前字符出现次数一半的数量添加到 jg 字符串中
            // 这样 jg 就包含了回文串的前半部分（按字典序排列）
            for(int i = 0; i < val / 2; ++i){ // 使用 ++i 稍微高效一点
                jg += key;
            }
        }

        // 构建最终的回文串
        string re; // 用于存储回文串的后半部分（前半部分的逆序）
        if(flag){ // 如果存在奇数次字符
            string temp = jg; // 复制前半部分
            reverse(temp.begin(), temp.end()); // 反转得到后半部分
            re = temp;
            // 最终结果是 前半部分 + 中间字符 + 后半部分
            return jg + ch + re;        //太典了太颠了，中途插入用left+ch+right
        }
        else{ // 如果所有字符都出现偶数次
            string temp = jg; // 复制前半部分
            reverse(temp.begin(), temp.end()); // 反转得到后半部分
            re = temp;
            // 最终结果是 前半部分 + 后半部分
            return jg + re;
        }
        /*
        // --- 原代码的后半部分逻辑，也可以用 reverse 实现 ---原来我的写法，reverse(jg.rbegin()+1,jg.rend())
        if(flag){ // 如果存在奇数次字符
            jg += ch; // 将中间字符加到 jg 的末尾
            //cout<<"jg="<<jg<<endl;
            // 从 jg 的倒数第二个字符开始反向迭代到开头，构造后半部分 re
            string re(jg.rbegin()+1, jg.rend());
            //cout<<re<<" jg="<<jg<<endl;
            // 返回 jg（前半部分+中间）+ re（前半部分的逆序）
            return jg + re;
        }
        else{ // 如果所有字符都出现偶数次
            // 从 jg 的最后一个字符开始反向迭代到开头，构造后半部分 re
            string re(jg.rbegin(), jg.rend());
            //cout<<re<<" jg="<<jg<<endl;
            // 返回 jg（前半部分）+ re（前半部分的逆序）
            return jg + re;
        }
        */
    }
};;