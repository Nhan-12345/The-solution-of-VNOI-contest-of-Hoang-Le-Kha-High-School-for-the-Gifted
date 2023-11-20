#include <bits/stdc++.h>
#define N int(1e5)
using namespace std;
int m, n, a[N+3], cnt[3][N+3];
int main()
{
    freopen("olympic.inp","r",stdin);
    freopen("olympic.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        {
            cnt[1][i]=cnt[1][i-1];
            cnt[2][i]=cnt[2][i-1];
            cnt[3][i]=cnt[3][i-1];
            cin>>a[i];
            cnt[a[i]][i]++;
        }
    for (int i=1; i<=m; i++)
        {
            int l, r;
            cin>>l>>r;
            cout<<cnt[1][r]-cnt[1][l-1]<<" ";
            cout<<cnt[2][r]-cnt[2][l-1]<<" ";
            cout<<cnt[3][r]-cnt[3][l-1]<<'\n';
        }
    return 0;
}
