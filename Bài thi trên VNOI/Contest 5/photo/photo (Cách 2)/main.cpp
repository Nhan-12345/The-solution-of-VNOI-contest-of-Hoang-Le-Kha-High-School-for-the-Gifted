#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e6 + 5;
const int N = 1e6 + 5;
int n, x, y, VN = -inf, TT = -inf, M = -inf, ans = inf;
int main()
{
    freopen ("photo.inp","r",stdin);
    freopen ("photo.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=1; i <= n; ++i){
        cin >> x >> y;
        if (y == 1) VN = x;
        if (y == 2) TT = x;
        if (y == 3) M = x;
        ans = min(ans, x - min({VN, TT, M}));
    }
        cout << ans;
    return 0;
}
