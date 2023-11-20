#include <bits/stdc++.h>
#define N int(50)
using namespace std;
int a[N+2], n, m, ans, dem;
int main()
{
    freopen("election.inp","r",stdin);
    freopen("election.out","w",stdout);
    cin>>n>>m;
    if (m==1)
        cout<<0;
    else
    {
        for (int i=1; i<=n; i++) cin>>a[i];
        sort (a+1, a+n+1, greater<int>());
        if (a[1]>=m)
            cout<<1;
        else
        {
            for (int i=1; i<n; i++)
            {
                ans+=a[i]-1;
                dem++;
            }
            if (ans<m)
                cout<<-1;
            else
                cout<<dem;
        }
    }
    return 0;
}
