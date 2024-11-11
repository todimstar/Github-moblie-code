#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;  // 读取测试用例的个数

    while (T--) {
        int n;
        cin >> n;  // 读取序列的长度
        vector<int> a(n);

        // 读取序列
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool valid = true;
        // 遍历数组，检查相邻元素是否有倍数关系
        for (int i = 0; i < n - 1; i++) {
            if (a[i] % a[i + 1] != 0 && a[i + 1] % a[i] != 0) {
                valid = false;
                break;
            }
        }

        // 输出结果
        if (valid) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
