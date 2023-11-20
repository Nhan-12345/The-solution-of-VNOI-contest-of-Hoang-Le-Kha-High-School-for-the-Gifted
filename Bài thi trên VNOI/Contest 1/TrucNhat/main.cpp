#include <bits/stdc++.h>
#define N 100
using namespace std;
int n, a[N+2];
long long BCNN(long long x, long long y)
{
    return x*y/__gcd(x,y);
}
int main()
{
    freopen("tn.inp","r",stdin);
    freopen("tn.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    long long B=a[1];
    for (int i=2; i<=n; i++)
        B=BCNN(B,a[i]);
    cout<<B<<'\n';
        for (int i=1; i<=n; i++)
        cout<<B/a[i]<<" ";
    return 0;
}
