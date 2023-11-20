#include <bits/stdc++.h>
#define N int(1e5)
using namespace std;
int n, s, ant=0, a[N+2];
int main()
{
    freopen ("cpair.inp","r",stdin);
    freopen ("cpair.out","w",stdout);
    cin>>n>>s;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        ant+=a[s-x];
        a[x]++;
    }
    cout<<ant;
    return 0;
}
