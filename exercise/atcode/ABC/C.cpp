#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

struct Node {
    ll head; // 蛇的头部坐标
    ll len;  // 蛇的长度
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    queue<Node> snakes;
    vector<int> snakeshead;
    ll l_head=0,r_head=0;
    ll offset = 0; // 全局偏移量

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            ll l;
            cin >> l;
            if (snakes.empty()) {
                snakes.push({0, l});
            } else {
                Node last = snakes.back();
                snakes.push({last.head + last.len, l});
            }
            snakeshead.push_back(snakes.back().head);
            r_head++; // 更新右点
        } else if (type == 2) {
            Node front = snakes.front();
            snakes.pop();
            offset += front.len; // 更新全局偏移量
            l_head++; // 更新左点
        } else if (type == 3) {
            int k;
            cin >> k;
            /*queue<Node> temp = snakes;
            for (int i = 1; i < k; ++i) {
                temp.pop();
            }*/
            cout << (snakeshead[k-1+l_head] - offset) << "\n";
        }
    }

    return 0;
}