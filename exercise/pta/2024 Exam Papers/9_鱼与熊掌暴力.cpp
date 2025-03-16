#include<iostream>	
#include<vector>
#include<string>

using namespace std;

const int N = 1e5 + 13;
typedef long long ll;

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n + 13);

    for (int i = 0; i < n; i++) {//i人
        int k, t;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> t;
            map[i].push_back(t);//对应i人的物品栏
        }
    }
    int q, a, b;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        int sum = 0;
        for (int j = 0; j < n; j++) {//遍历n个人
            int cnt = 0;
            for (int k : map[j]) {
                if (k == a || k == b) {
                    cnt++;
                }
            }
            if (cnt == 2)sum++;
        }
        cout << sum << endl;
    }

    return 0;
}
