#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define all(x) x.begin(), x.end()
#define frt(i,a,b) for(int i=a; i<=b; i++)
#define frg(i,a,b) for(int i=a; i>=b; i--)

using namespace std;
const int N = 5e5 + 2;
int n, a[N], w[N];

void nenmang()
{
    int c[n], cnt[n];
    frt(i,1,n)
        if(!cnt[a[i]]){
            c[i] = a[i];
            cnt[a[i]]++;
        }
    sort(c+1, c+n+1);
    frt(i,1,n)
        cout << c[i] <<' ';
    frt(i,1,n)
        a[i] = lower_bound(c+1, c+n+1, a[i]) - c;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("", "r", stdin);
    freopen("", "w", stdout);
    cin >> n;
    frt(i,1,n)
        cin >> a[i] >> w[i];
    nenmang();
//    frt(i,1,n)
//        cout << a[i] << ' ' << w[i] << '\n';
    return 0;
}
