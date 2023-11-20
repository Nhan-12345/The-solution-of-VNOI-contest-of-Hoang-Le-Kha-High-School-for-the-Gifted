#include <bits/stdc++.h>

using namespace std;
int n, m, w[101], v[101], a[1001];
int value, weight, ans;

void Try(int k)
{
    for (int i=0; i<=1; i++)
    {
        weight +=i*w[k];
        value +=i*v[k];
        if (weight<=m)
            if (k==n)
                ans=max(ans,value);
            else
                Try(k+1);
        weight -=i*w[k];
        value -=i*v[k];

    }
}
int main()
{
    freopen ("caitui.inp","r",stdin);
    freopen ("caitui.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    cin>>w[i]>>v[i];
    Try(1);
    cout<<ans;
    return 0;
}
