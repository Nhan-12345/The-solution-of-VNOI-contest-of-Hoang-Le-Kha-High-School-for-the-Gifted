#include <bits/stdc++.h>
#define N int(1e5)
using namespace std;
long long n, k, a[N+2], dem=1;

int main()
{
    freopen ("groups.inp","r",stdin);
    freopen ("groups.out","w",stdout);
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]<0)
            a[i]=abs(a[i]);
    }

    sort (a+1,a+n+1);
    int p=1;
    for (int i=2; i<=n; i++)
    {
        if (a[i]-a[p]>k)
        {
            dem++;
            p=i;
        }
    }
    cout<<dem;
    return 0;
}
