#include<iostream>
using namespace std;
#define int long long
const int N = 1e7;

int f[N];

signed main()
{
    int n;
    cin >> n;
    int a,b,c;
    cin >> a >> b >> c;
    f[0] = 1;
    for(int i = 1;i <= n; i++)
    {
        if(i >= a)f[i] += f[i-a];
        if(i >= b)f[i] += f[i-b];
        if(i >= c)f[i] += f[i-c];
    }
    cout << f[n]%1000000007 << endl;
    return 0;
}
