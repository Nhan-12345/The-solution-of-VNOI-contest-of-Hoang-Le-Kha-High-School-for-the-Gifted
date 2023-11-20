#include <bits/stdc++.h>
#define N int(1e5)
using namespace std;
long long n, a[N+2], s1, s2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen ("cgame.inp","r",stdin);
    freopen ("cgame.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    int l=1, r=n, d=0;
    while (l<=r){
        if (d==0)
            s1+=max(a[l],a[r]);
        else
            s2+=max(a[l],a[r]);
        if (a[l]>a[r])
            l++;
        else
            r--;
        d=1-d;
    }
    cout<<s1<<" "<<s2;
    return 0;
}
