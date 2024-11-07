#include <iostream>//算法注释：贪心算法，心得：注意L,R都是负数直接+	，题目网址：https://atcoder.jp/contests/abc362/tasks/abc362_c

using namespace std;

#define int long long
const int N = 2e5 + 10;
int n, s, b;
int L[N], R[N], a[N];

bool solve() {
    // 判断初始和是否在允许范围内
    if (s > 0 || b < 0) {
        return false; // 无法调整
    }

    int cha = s; // 当前和距离0的差距，初始为s，是负数
    for (int i = 0; i < n; i++) {
      // 如果cnt为0，说明已经调整完毕
        if (cha == 0) {
            break;//维持之前的L[i]就行，再见了
        }else{
  
          // 更新当前的a[i]和差距
          if(-cha >= R[i] - L[i]){//看要补偿r-l还是最后一次补偿r-l内的cha
            a[i] += R[i] - L[i];
            cha += R[i]-L[i];//cha同步减少，这跟牛客不同，牛客的cha是正的这里是负的
          }else{
            a[i] += -cha;//最后一次补偿-cha
            cha=0;//记得回位cha
          }

        
        }
    }

    return true; // 判断最终是否调整到0
}

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> n;
    
    s = 0, b = 0;
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
        a[i] = L[i];
        s += L[i];
        b += R[i];
    }

    if (!solve()) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
