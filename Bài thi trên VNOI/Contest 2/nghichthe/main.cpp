#include <bits/stdc++.h>
using namespace std;
int n, a[103];
int main()
{
    freopen ("nghichthe1.inp","r",stdin);
    freopen ("nghichthe1.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    int p=0;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=i; j++)
        {
            if (a[i]<a[j]) ans++;
            if (j==i)
            {
                if (a[j]>=a[i])
                {
                    p=ans;
                    ans=0;
                }
            }
        }
        cout<<ans<<" ";
    }
    return 0;
}
