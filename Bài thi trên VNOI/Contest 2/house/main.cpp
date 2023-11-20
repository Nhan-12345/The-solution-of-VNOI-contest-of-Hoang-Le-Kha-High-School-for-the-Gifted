#include <bits/stdc++.h>
#define N int(2503)
using namespace std;
string P;
int n, ans, a[N+3];
int main()
{
    freopen("house.inp","r",stdin);
    freopen("house.out","w",stdout);
    cin>>n>>P;
    P=" "+P;
    a[1]=1;
    for (int i=2; i<=n; i++)
    {
    if (P[i]==P[i-1])
        a[i]=a[i-1]+1;
    else
        a[i]=1;
    }
    a[n+1]=1;
    for (int i=1; i<=n+1; i++)
    {
        if(a[i]==1)
        ans+=a[i-1]/2;
    }
    cout<<ans;
    return 0;
}
