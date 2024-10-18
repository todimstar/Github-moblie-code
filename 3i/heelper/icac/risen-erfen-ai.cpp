#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 10010;
long long a[N];

// 判断能否通过最多k次操作，使所有相邻花朵差的绝对值不超过x
bool pd(int x, int n, int k) {
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (abs(a[i] - a[i - 1]) > x) {
            ++cnt; // 如果相邻差值超过x，就需要一次操作
        }
    }
    return cnt <= k; // 检查所需的操作次数是否在允许的范围内
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 初始化二分法的上下界
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        r = max(r, (int)abs(a[i] - a[i - 1])); // 找到初始最大差值作为二分的上界
    }

    // 二分法查找最小的凌乱度
    while (l < r) {
        int mid = (l + r) / 2;
        if (pd(mid, n, k)) {
            r = mid; // 凌乱度可以达到mid，尝试更小的凌乱度
        } else {
            l = mid + 1; // 凌乱度不行，增大范围
        }
    }

    // 输出最小的凌乱度
    cout << l << endl;

    return 0;
}
