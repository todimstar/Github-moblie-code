//算法注释：二分	，心得：还是l<r好，不用特判r<0、l>右边界	，题目网址：https://www.marscode.cn/practice/36ln82w7r9vn2q?problem_id=7414004855076208684
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

ll findClosest(const vector<ll>& b, ll target) {//主体采用l<r，则不用特判r<0和l>b.size()，记得是直接返回l就行
    int l = 0, r = b.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (b[mid] < target) {
            l = mid + 1; // 目标值在右半部分
        } else {
            r = mid ; // 目标值在左半部分
        }
    }

    /*if (abs(b[l] - target) > abs(b[r] - target)) {
        return b[r];
    }*/
    return b[l];
}

// 二分查找l<=r，主体好记，但是结果b[r]要特判r<0，l>=b.size()，甚至abs(b[l] - target) < abs(b[r] - target)，好像此时的l!=r，返回只有l才通过
ll findClosest(const vector<ll>& b, ll target) {
    int l = 0, r = b.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (b[mid] < target) {
            l = mid + 1; // 目标值在右半部分
        } else {
            r = mid - 1; // 目标值在左半部分
        }
    }

    // 检查 l 和 r 哪个更接近 target
    if (l >= b.size()) {
        return b[r]; // l 越界，返回 r
    }
    if (r < 0) {
        return b[l]; // r 越界，返回 l
    }
    /*if (abs(b[l] - target) < abs(b[r] - target)) {
        return b[l];
    }*/
    return b[r];//b[r]不通过，而b[l]通过
}

int solution(int n, int m, int k, vector<int>& a, vector<int>& b) {
    // 将 a 和 b 转换为 long long 类型
    vector<ll> a_ll(a.begin(), a.end());
    vector<ll> b_ll(b.begin(), b.end());

    // 排序
    sort(a_ll.begin(), a_ll.end());
    sort(b_ll.begin(), b_ll.end());

    ll minVal = LLONG_MAX;

    // 遍历 a
    for (int i = 0; i < n; i++) {
        // 目标值 1: a[i] - k
        ll target1 = a_ll[i] - k;
        ll closest1 = findClosest(b_ll, target1);
        ll val1 = abs((a_ll[i] - closest1) * (a_ll[i] - closest1) - k * k);

        // 目标值 2: a[i] + k
        ll target2 = a_ll[i] + k;
        ll closest2 = findClosest(b_ll, target2);
        ll val2 = abs((a_ll[i] - closest2) * (a_ll[i] - closest2) - k * k);

        // 更新最小值
        minVal = min(minVal, min(val1, val2));
    }

    return minVal;
}

int main() {
    // 测试用例 1
    vector<int> a1 = {5, 3, 4, 1, 2};
    vector<int> b1 = {0, 6, 7, 9, 8};
    cout << (solution(5, 5, 1, a1, b1) == 0) << endl; // 预期输出: 1 (true)

    // 测试用例 2
    vector<int> a2 = {5, 3, 4, 1, 2};
    vector<int> b2 = {0, 6, 7, 9, 8};
    cout << (solution(5, 5, 0, a2, b2) == 1) << endl; // 预期输出: 1 (true)

    // 测试用例 3
    vector<int> a3 = {5, 3, 4, 1, 2};
    vector<int> b3 = {0, 6, 7, 9, 8, 11};
    cout << (solution(5, 6, 3, a3, b3) == 0) << endl; // 预期输出: 1 (true)

    return 0;
}