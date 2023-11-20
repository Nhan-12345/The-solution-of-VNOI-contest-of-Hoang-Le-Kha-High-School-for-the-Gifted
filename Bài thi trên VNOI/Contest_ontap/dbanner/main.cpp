#include <bits/stdc++.h>
#define N 100000
using namespace std;
long long a[N+2], ans=-1e9;
int n;
int main()
{
    freopen ("dbanner.inp","r",stdin);
    freopen ("dbanner.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++){
        int L, R;
        for (int j=i-1; j>=0; j--)
            if (a[j]<a[i])
        {
                L=j;
                break;
        }
        for (int j=i+1; j<=n+1; j++)
            if (a[i]>a[j])
        {
                R=j;
                break;
        }
        ans=max(ans,a[i]*(R-L-1));
    }
    cout<<ans;
    return 0;
}
