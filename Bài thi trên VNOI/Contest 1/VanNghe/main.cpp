#include <bits/stdc++.h>

using namespace std;
int n,m;
int main()
{
    freopen("vn.inp","r",stdin);
    freopen("vn.out","w",stdout);
    cin>>n>>m;
    int d=__gcd(n,m);
    cout<<d<<'\n';
    cout<<n/d<<" "<<m/d;
    return 0;
}
