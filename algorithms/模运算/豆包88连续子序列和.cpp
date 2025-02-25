#include <iostream>     //题目地址：https://www.marscode.cn/practice/36ln82w7r9vn2q?problem_id=7414004855076306988
#include <vector>           //哈希表记录模 b 的结果出现的次数，以实现计算子序列和能被 b 整除的次数
#include <unordered_map>

using namespace std;

int solution(int n, int b, vector<int>& sequence) {
    // 简单一个前缀和数组
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + sequence[i];
    }

    // 哈希表记录模 b 的结果出现的次数
    unordered_map<int, int> count;//哈希表最多到b
    count[0] = 1; // 空序列的前缀和为 0，倒也是关键，之后同被模得0的也有个伴，实现他-这个空序列得一次

    int result = 0;
    for (int i = 1; i <= n; i++) {
        int mod = prefix[i] % b;
        if (mod < 0) mod += b; // 处理负数情况
        if (count.find(mod) != count.end()) {
            result += count[mod];//之前count中能也被模为当前mod的，与当前i都能组成一个子序列，实现这个mod-之前的mod=0，实现整除
        }
        count[mod]++;//记录当前i能模得mod
    }

    return result;
}

int main() {
    // 测试用例 1
    int n1 = 3, b1 = 3;
    vector<int> sequence1 = {1, 2, 3};
    cout << solution(n1, b1, sequence1) << endl; // 预期输出: 3

    // 测试用例 2
    int n2 = 4, b2 = 5;
    vector<int> sequence2 = {5, 10, 15, 20};
    cout << solution(n2, b2, sequence2) << endl; // 预期输出: 10

    // 测试用例 3
    int n3 = 5, b3 = 2;
    vector<int> sequence3 = {1, 2, 3, 4, 5};
    cout << solution(n3, b3, sequence3) << endl; // 预期输出: 6

    return 0;
}