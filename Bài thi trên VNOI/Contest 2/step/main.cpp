#include <bits/stdc++.h>
using namespace std;
bool bacthang(int x)
{
    while (x>=10)
    {
    int r=x%10;
    x/=10;
    if (x%10>r) return 0;
    }
    return 1;
}
int n, ans=0;
int main()
{
    freopen ("step.inp","r",stdin);
    freopen ("step.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        if (x>=10&&bacthang(x))
            ans++;
    }
    cout<<ans;
    return 0;
}
