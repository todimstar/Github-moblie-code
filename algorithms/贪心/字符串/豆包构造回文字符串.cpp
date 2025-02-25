#include <iostream> //算法注释：贪心	，心得：贪心的构造左半边的回文，(n/2)的尝试是否合格	，题目网址：https://www.marscode.cn/practice/36ln82w7r9vn2q?problem_id=7424436653623181356
#include <string>
#include <vector>
using namespace std;

/*解题思路
回文字符串的性质：

    回文字符串的左右部分是对称的，因此只需要构造左半部分，右半部分可以通过对称性得到。

    如果字符串长度为奇数，中间字符可以单独处理。

字典序的比较规则：

    从左到右逐字符比较，直到找到第一个不同的字符。

    较小的字符所在的字符串字典序较小。

贪心算法的应用：

    从左到右逐字符调整，确保 t 的字典序小于 s。

    在调整时，尽可能让 t 的字典序大。
*/

string solution(const string &s)
{
    int n = s.length();
    vector<char> t(s.begin(), s.end()); // 将字符串 s 转换为字符数组 t，方便修改

    /*  auto build = [&](const vector<char>& t) -> vector<char>
    这是 C++ 中的 Lambda 表达式，用于定义一个匿名函数。它的语法如下：

    auto 函数名 = [捕获列表](参数列表) -> 返回类型 { 函数体 };
    [&]：捕获列表中的 & 表示以引用方式捕获外部变量（即可以在 Lambda 函数中访问和修改外部变量）。

    (const vector<char>& t)：参数列表，表示 Lambda 函数接受一个 vector<char> 类型的参数 t。

    -> vector<char>：指定 Lambda 函数的返回类型为 vector<char>。

    { 函数体 }：Lambda 函数的实现逻辑。

    在代码中，build 是一个 Lambda 函数，用于构造回文字符串。它的作用是将输入的字符数组 t 转换为回文字符串。
    */
    // 构造回文字符串的函数
    auto build = [&](const vector<char> &t) -> vector<char>
    {
        vector<char> s = t;   // 复制一份 t
        int l = 0, r = n - 1; // 左右指针
        while (l < r)
        {
            s[r] = s[l]; // 将右半部分设置为左半部分的镜像
            l++;
            r--;
        }
        return s;
    };

    // 构造原始字符串的回文字符串
    vector<char> palindrome = build(t);

    // 检查回文字符串的字典序是否小于原字符串
    if (palindrome < t)
    {
        return string(palindrome.begin(), palindrome.end()); // 如果满足条件，直接返回
    }
    else
    {
        // 如果不满足条件，则需要调整字符
        int i = (n - 1) / 2; // 从中间位置开始向左遍历
        while (i >= 0)
        {
            if (t[i] == 'a')
            {
                // 如果当前字符是 'a'，则无法调整，继续向左遍历
                t[i] = 'z'; // 设置为 'z'，以便后续调整
            }
            else
            {
                // 否则，将当前字符减 1（调整为比原字符小的最大可能字符）
                t[i] = t[i] - 1;
                break; // 调整后退出循环
            }
            i--; // 继续向左遍历
        }

        // 如果所有字符都无法调整（如所有字符已经是 'a'），则返回 '-1'
        if (i == -1)
        {
            return "-1";
        }
        else
        {
            // 否则，构造调整后的回文字符串
            vector<char> ans = build(t);
            return string(ans.begin(), ans.end()); // 将字符数组转换为字符串并返回
        }
    }
}

int main()
{
    // 测试样例
    cout << (solution("abc") == "aba") << endl;     // 输出 1（true）
    cout << (solution("cba") == "cac") << endl;     // 输出 1（true）
    cout << (solution("aaa") == "-1") << endl;      // 输出 1（true）
    cout << (solution("bcaaa") == "bbzbb") << endl; // 输出 1（true）
    cout << (solution("fbaaa") == "fazaf") << endl; // 两个都是a->z的应用
    return 0;
}