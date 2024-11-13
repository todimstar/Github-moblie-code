// NowCoder 小红开宝箱
// https://ac.nowcoder.com/acm/contest/94879/E 2024-11-08 19:24:01

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

int n;
vector<int> options[MAXN];  // 每个步骤的可选柱子
int match_pillar[MAXN];     // 每个柱子匹配的步骤
bool visited[MAXN];         // DFS 中用于标记已访问的柱子

bool bpm(int u) {
  for (int v : options[u]) {
    if (!visited[v]) {
      visited[v] = true;
      if (match_pillar[v] == -1 || bpm(match_pillar[v])) {
        match_pillar[v] = u;
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  // 读取输入
  for (int i = 1; i <= n; ++i) {
    int k;
    cin >> k;
    options[i].resize(k);
    for (int j = 0; j < k; ++j) {
      cin >> options[i][j];
    }
  }

  memset(match_pillar, -1, sizeof(match_pillar));

  bool possible = true;
  // 尝试为每个步骤匹配一个柱子
  for (int i = 1; i <= n; ++i) {
    memset(visited, 0, sizeof(visited));
    if (!bpm(i)) {
      possible = false;
      break;
    }
  }

  if (!possible) {
    cout << "kou is angry" << endl;
  } else {
    // 构建击打序列
    vector<int> sequence(n + 1);
    for (int v = 1; v <= n; ++v) {
      if (match_pillar[v] != -1) {
        sequence[match_pillar[v]] = v;
      }
    }
    // 输出序列
    for (int i = 1; i <= n; ++i) {
      cout << sequence[i] << (i == n ? '\n' : ' ');
    }
  }

  return 0;
}
/*这道题可以看作是一个二分图匹配问题，具体来说是最大匹配问题，并使用匈牙利算法进行求解。我们将每个击打步骤视为图的一侧，将柱子视为图的另一侧。每个步骤与它可能击打的柱子有连边。目标是找到一个匹配，使得每个步骤都能匹配到一个柱子。
算法解释
1.	建模为二分图匹配：
o	每个击打步骤 iii 是图的一侧的顶点集。
o	每个柱子 ppp 是图的另一侧的顶点集。
o	如果第 iii 次击打可以击打柱子 ppp，那么在图中就有一条从 iii 到 ppp 的边。
2.	匈牙利算法：
o	通过DFS尝试为每个击打步骤找到匹配。如果当前柱子已经被匹配过，则尝试通过递归重新安排匹配，使得当前步骤也能匹配成功。
o	匈牙利算法的核心是通过DFS搜索未访问过的路径，来寻找增广路径并进行匹配更新。
为什么使用普通DFS可能会出问题？
使用普通DFS可能会有以下问题：
•	匹配要求：普通的DFS不能保证找到最大匹配，因为它不考虑递归地替换已占用的节点。
•	增广路径：匈牙利算法的核心是寻找增广路径来调整现有的匹配。普通的DFS不会尝试释放和重新分配已匹配的路径，所以会导致匹配失败。
代码讲解
cpp
复制代码
bool bpm(int u) {
  for (int v : options[u]) {  // 遍历当前步骤 u 可以匹配的柱子 v
    if (!visited[v]) {        // 如果柱子 v 未访问过
      visited[v] = true;      // 标记为已访问
      // 如果柱子 v 没有匹配步骤，或可以找到一个增广路径
      if (match_pillar[v] == -1 || bpm(match_pillar[v])) {
        match_pillar[v] = u;  // 将柱子 v 匹配到步骤 u
        return true;          // 找到匹配，返回 true
      }
    }
  }
  return false;  // 没有找到匹配
}
复杂度分析
•	时间复杂度：O(n⋅m)O(n \cdot m)O(n⋅m)，其中 nnn 是步骤数量，mmm 是可能的柱子数量。由于每次匹配时，DFS 的时间复杂度为 O(m)O(m)O(m)，所以总复杂度为 O(n⋅m)O(n \cdot m)O(n⋅m)。
•	空间复杂度：O(n+m)O(n + m)O(n+m)，用于存储邻接列表和匹配信息。
代码解读
1.	输入处理：读取输入并存储每个步骤可以匹配的柱子。
2.	初始化：初始化 match_pillar 数组为 -1，表示初始时没有柱子被匹配。
3.	匹配过程：使用 bpm() 函数尝试匹配每个步骤。
4.	输出结果：
o	如果匹配失败，输出 "kou is angry"。
o	否则输出合法的击打序列。
为什么这题解法有效？
匈牙利算法通过递归和增广路径的思想保证每次匹配的有效性和最大性，确保了如果存在可行的击打顺序，就一定能找到。普通DFS在这种情况下不能保证重新分配已匹配节点，因此无法找到有效解。
*/