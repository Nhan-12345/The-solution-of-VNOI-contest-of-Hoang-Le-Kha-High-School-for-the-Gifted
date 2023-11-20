#include <bits/stdc++.h>
using namespace std;
int X, Y, ans, d;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen ("cau1.inp","r",stdin);
    freopen ("cau1.out","w",stdout);
    cin>>X>>Y;
    d=__gcd(X,Y);
    for (int i=1; i<=d; i++){
        if (d%i==0)
            ans++;
    }
    cout<<ans;
    return 0;
}
