#include <bits/stdc++.h>
#define N int(1e5)
using namespace std;
int n, a[N+3], s;
int main()
{
    freopen("INSUL.INP","r",stdin);
    freopen("INSUL.OUT","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++)
        s+=a[i];
    for(int i=1; i<=n/2; i++)
        s+=a[n+1-i]-a[i];
    cout<<s;
    return 0;
}
