#include <bits/stdc++.h>
#define N 30000
using namespace std;
int d[N+2], v[N+2], n, m;
long long s;
//----------------------------------------
bool cmp(int X, int Y)
{
    return X>Y;
}
//----------------------------------------
int main()
{
    freopen ("thamquan.inp","r",stdin);
    freopen ("thamquan.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>d[i];
    for (int j=1; j<=m; j++) cin>>v[j];
    sort (v+1,v+m+1);
    sort (d+1,d+n+1,cmp);
    for (int i=1; i<=n; i++)
    {
          s+= d[i]*v[i];
    }
    cout<<s;
    return 0;
}
