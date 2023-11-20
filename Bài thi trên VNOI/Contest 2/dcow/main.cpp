#include <bits/stdc++.h>
#define N int(1e5)
using namespace std;
int cnt[N+3], n, a[N+3];

int main()
{
    freopen ("dcow.inp","r",stdin);
    freopen ("dcow.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        {
            cnt[a[i]]++;
        }
        int s;
        int k=0;
    for (int i=1; i<=N; i++)\
    {
        s=cnt[i]*(cnt[i]-1)/2;
        k=k+s;
    }
    cout<<k;
    return 0;
}
