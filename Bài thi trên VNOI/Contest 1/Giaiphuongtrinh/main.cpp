#include <bits/stdc++.h>
#define ll long long
#define inf int(2e9)
using namespace std;
ll n, res = inf;
ll S(ll x)
{
    ll sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x = x / 10;
    }
    return sum;
}
int main()
{
    cin >> n;
    for (ll t = 1; t <= 90; t++)
    {
        ll x = (-t + sqrt(t * t + 4 * n)) / 2;
        if (x * x + S(x) * x - n == 0)
            res = min(res,x);
    }
    if (res == inf) cout << -1;
    else cout << res;
    return 0;
}
