#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define long long ll;
const int N = 10010;
long long a[N], b[N],dp[N];

// 判断能否通过最多k次操作，使所有相邻花朵差的绝对值不超过x
bool pd(int x, int n, int k)
{
    int cnt = 0;
    for (int i = 1; i < n; ++i)
    {
        if (abs(a[i] - a[i - 1]) > x)
        {
            ++cnt; // 如果相邻差值超过x，就需要一次操作
            if (a[i] > a[i - 1])
                a[i] -= (abs(a[i] - a[i - 1]) - x);
            else
                a[i] += (abs(a[i] - a[i - 1]) - x);
        }
    }
    return cnt <= k; // 检查所需的操作次数是否在允许的范围内
}

void remove(int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}

bool check(ll x)    //大佬的法二--一南
{
    ll res = n;
    for (int i = 1; i <= n; i++)
        dp[i] = i;
    dp[1] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (abs(num[i] - num[j]) <= (i - j) * x)
            {
                dp[i] = min(dp[i], dp[j] + (i - j - 1));
                res = min(res, n - i + dp[i]);
            }
    res = min(res, dp[n]);
    if (res <= k)
        return 1;
    return 0;
}

int main()
{
    int n, k;
    while (true)
    {
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
            a[i] = b[i];
        }

        // 初始化二分法的上下界
        int l = 0, r = 1e9 + 10;

        // 二分法查找最小的凌乱度
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (pd(mid, n, k))
            {
                r = mid; // 凌乱度可以达到mid，尝试更小的凌乱度
            }
            else
            {
                l = mid + 1; // 凌乱度不行，增大范围
            }
            remove(n);
        }

        // 输出最小的凌乱度
        cout << l << endl;
    }

    return 0;
}

/*
二分答案，然后check考虑用二维dp数组维护几个信息，
dp[i][j]表示第i个数执行j次修改后的情况，第i个数有修改和不修改两种状态，
不修改的话从dp[i-1][j]转移，修改的话，第i个数可以表示一个区间，在区间的任意值都是可行的，这个区间要从dp[i-1][j-1]去得到，
同时dp[i][j]要维护两个信息flag1，flag2，分别表示修改是可行的和不修改是可行的。
最后检查dp[n][0~k]的flag是否存在真值即可
*/