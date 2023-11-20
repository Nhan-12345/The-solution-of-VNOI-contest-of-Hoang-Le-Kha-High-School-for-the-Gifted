#include <bits/stdc++.h>
#define N int(1e5)
using namespace std;
int cntn[2*N+2], cntm[2*N+2];
int n,m,g,h;
int main()
{
    freopen ("bset.inp","r",stdin);
    freopen ("bset.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        cntn[x+N]=1;
    }
    for (int j=1; j<=m; j++)
    {
        int x;
        cin>>x;
        cntm[x+N]=1;
    }
    for (int x=1; x<=2*N; x++)
    {
    if (cntn[x]==1&&cntm[x]==1) g++;
    if (cntn[x]==1||cntm[x]==1) h++;
    }
    cout<<h<<" "<<g;
    return 0;
}
