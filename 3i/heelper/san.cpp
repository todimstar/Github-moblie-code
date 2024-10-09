#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    long long a, b, c, m, n, i, j, k;
    scanf("%lld %lld %lld", &a, &b, &c);
    m = a + b + C;
    n = min(a, b);
    i = min(n, c);
    j = max(a, b);
    k = max(j, c);
    i = i * 2;
    m = a + b + c + i / 2;
    if (i < k)
    {
        if (m - k > k)
            printf("Yes\n");
        else
            printf("No\n");
    }
    if (i >= k){
        if (m - i > i)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}