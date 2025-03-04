#include <iostream>
using namespace std;

int main() {
    int n0, n1, n;
    cin >> n0 >> n1 >> n;

    int n0num = 0, n1num = 0;
    int min_diff = 1e9;
    bool found = false;

    for (int i = 1; i < n; ++i) { // 遍历可能的女生寝室数量
        int m = n - i; // 男生寝室数量
        if (m <= 0) continue; // 确保男生寝室数量合法

        if (n0 % i == 0 && n1 % m == 0) {
            int k0 = n0 / i; // 每个女生寝室人数
            int k1 = n1 / m; // 每个男生寝室人数

            if (k0 >= 2 && k1 >= 2) { // 检查人数下限
                int diff = abs(k0 - k1);
                if (diff < min_diff) {
                    min_diff = diff;
                    n0num = i;
                    n1num = m;
                    found = true;
                }
            }
        }
    }

    if (found) {
        cout << n0num << " " << n1num;
    } else {
        cout << "No Solution";
    }

    return 0;
}