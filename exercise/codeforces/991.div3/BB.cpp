#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL
void solve()
{
    int n;
    cin >> n;
    vl a(n);
    ll sum1 = 0;
    ll sum2 = 0;
    ll cnt1 = 0;
    ll cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i & 1)
            sum1 += a[i], cnt1++;
        else
            sum2 += a[i], cnt2++;
    }
    if (n == 1)
    {
        cout << "YES\n";
    }
    if (sum1 % cnt1 || sum2 % cnt2 || sum1 / cnt1 != sum2 / cnt2)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int _ = 1;
    std::cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}