#include <bits/stdc++.h>
#define N 10000000
using namespace std;
int n;
long long a[N+2];
int main()
{
    freopen ("bkid.inp","r",stdin);
    freopen ("bkid.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    int j=1;
    for (int i=2; i<=n; i++)
    {
        if (a[i]>a[j])
        {
            cout<<i<<'\n';
        }
        else
        {
            cout<<j<<'\n';
            j=i;
        }
    }
    return 0;
}
