#include <bits/stdc++.h>
#define N int(1e5)
using namespace std;
int n, s, l, r, a[N+3], cnt[N+3];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=n; i++)
    {
        s+=a[i];
        cnt[i]=s;
    }
    for(int i=1; i<=n; i++)
    cout<<cnt[i]<<" ";
        cin>>l>>r;
        cout<<cnt[r]-cnt[l-1];
    return 0;
}
