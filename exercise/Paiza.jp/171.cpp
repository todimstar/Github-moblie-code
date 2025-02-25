#include <iostream> //算法注释：语法题	，心得：我真服了!!! 要注意看结果需要什么哇，不需要搞这么复杂的	，题目网址：https://paiza.jp/student/challenges/171/page/result
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    int best_rem = N + 1; // 初始化为一个较大的值，余数不可能超过N
    int best_mi = 0;
    int best_index = 0;
    for (int i = 0; i < M; ++i) {
        int mi;
        cin >> mi;
        int rem = N % mi;
        if (rem < best_rem) {
            best_rem = rem;
            best_mi = mi;
            best_index = i + 1;
        } else if (rem == best_rem) {
            if (mi > best_mi) {
                best_mi = mi;
                best_index = i + 1;
            }
        }
    }
    cout << best_index << endl;
    return 0;
}