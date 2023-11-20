#include <bits/stdc++.h>
#include <math.h>
#define N 100000
#define lli long long
using namespace std;
int a[N+3];
lli  n;
bool nguyenTo(int k)
{
    if (k<2) return false;
    for (int i=2; i*i<=k; i++)
        if (k%i==0) return false;
    return true;
}
int main()
{
    freopen ("TNUM.INP","r",stdin);
    freopen ("TNUM.OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
    {
     lli s = sqrt(a[i]);
        if (s*s==a[i]&&nguyenTo(s))
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
    return 0;
}
