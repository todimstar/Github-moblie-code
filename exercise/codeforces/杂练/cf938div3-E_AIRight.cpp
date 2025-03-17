/**
核心思路
贪心策略：从最大的 k（即 k = n）开始尝试，一旦找到可行的 k，直接返回。

翻转模拟：对于每个 k，模拟翻转过程，判断是否能让所有字符变为 1。

高效跟踪：用队列记录翻转操作的结束位置，避免重复计算。

关键概念详解
1. 为什么要从最大的 k 开始尝试？
因为题目要求最大的 k，所以从大到小遍历，一旦找到可行的 k，立刻返回，无需检查更小的 k。

2. 如何判断某个 k 是否可行？
从左到右遍历字符串，遇到需要翻转的位置时，记录翻转操作的结束位置。

队列的作用：跟踪所有未完成的翻转操作的结束位置。

奇偶性判断：翻转偶数次等于不翻转，奇数次等于翻转一次。

3. 如何计算当前字符的实际值？
假设原字符为 s[i]，当前已进行的翻转次数为 flipCount。

实际值 = (原字符的数值 + flipCount) % 2。

如果实际值为 0，必须在此处发起一次新的翻转。

具体步骤拆解（以 s = "00100", k = 3 为例）
初始化：flipCount = 0，队列为空。

处理第 0 个字符：

原值 s[0] = '0'，实际值 = (0 + 0) % 2 = 0 → 需要翻转。

发起翻转：结束位置为 0 + 3 = 3，队列变为 [3]，flipCount = 1。

处理第 1 个字符：

原值 s[1] = '0'，实际值 = (0 + 1) % 2 = 1 → 无需翻转。

处理第 2 个字符：

原值 s[2] = '1'，实际值 = (1 + 1) % 2 = 0 → 需要翻转。

发起翻转：结束位置为 2 + 3 = 5，队列变为 [3, 5]，flipCount = 2。

处理第 3 个字符：

检查队列：3 <= 3 → 弹出 3，flipCount = 1。

原值 s[3] = '0'，实际值 = (0 + 1) % 2 = 1 → 无需翻转。

处理第 4 个字符：

检查队列：5 > 4 → 不弹出。

原值 s[4] = '0'，实际值 = (0 + 1) % 2 = 1 → 无需翻转。

最终检查：所有字符处理后，队列中剩余的翻转操作会在后续位置结束，最终字符串变为 11111。
 */

#include <iostream>
#include <string>
#include <deque>

using namespace std;

bool isPossible(const string& s, int k) {
    int n = s.size();
    deque<int> flipEnds; // 存储翻转结束的位置
    int flipCount = 0;   // 当前生效的翻转次数

    for (int i = 0; i < n; ++i) {
        // 移除所有已经结束的翻转
        while (!flipEnds.empty() && flipEnds.front() <= i) {
            flipEnds.pop_front();
            flipCount--;
        }

        // 计算当前字符的实际值
        int current = (s[i] == '1') ? 1 : 0;
        int actual = (current + flipCount) % 2;

        if (actual == 0) { // 需要翻转
            if (i + k > n) return false; // 无法翻转，k太大
            flipCount++;
            flipEnds.push_back(i + k); // 记录翻转结束位置
        }
    }
    return true;
}

int findMaxK(const string& s) {
    int n = s.size();
    for (int k = n; k >= 1; --k) {
        if (isPossible(s, k)) {
            return k;
        }
    }
    return 1; // 至少k=1可行
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << findMaxK(s) << '\n';
    }

    return 0;
}