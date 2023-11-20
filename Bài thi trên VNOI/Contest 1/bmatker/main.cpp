#include <bits/stdc++.h>

using namespace std;
int n, y, k;
int main()
{
    freopen("bmarket.inp","r",stdin);
    freopen("bmarket.out","w",stdout);
    cin>>y>>k>>n;
    bool b = false;
    for (int d=1; d<=n/d; d++)
    {
        int x = k*d-y;
        if (x>0)
        {
            cout<<x<<" ";
            b = true;
        }
    }
        if(!b)
            cout<<-1;
    return 0;
}
