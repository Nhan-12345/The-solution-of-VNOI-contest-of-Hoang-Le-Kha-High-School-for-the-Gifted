#include <bits/stdc++.h>
#define ll long long
#define frt(i,a,b) for(int i=a; i<=b; i++)
#define frg(i,a,b) for(int i=a; i>=b; i--)


using namespace std;
const int N = 1e3 + 2;
int n, ans;
vector<int> a(N), b(N), c(N);
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("triangle.inp", "r", stdin);
    freopen("triangle.out", "w", stdout);

    cin >> n;
    frt(i,1,n) cin >> a[i];
    frt(i,1,n) cin >> b[i];
    frt(i,1,n) cin >> c[i];

    sort(c.begin(), c.end());

    frt(i,1,n)
        frt(j,1,n){
            int kq1 = abs(a[i] - b[j]);
            int kq2 = a[i] + b[j];
            int k1 = upper_bound(c.begin(), c.end(), kq1) - c.end();
            int k2 = lower_bound(c.begin(), c.end(), kq2) - c.end();
            ans += k2-k1;
        }

    cout << ans;
    return 0;
}
/**
3
2 3 1
4 4 9
8 5 2
**/
