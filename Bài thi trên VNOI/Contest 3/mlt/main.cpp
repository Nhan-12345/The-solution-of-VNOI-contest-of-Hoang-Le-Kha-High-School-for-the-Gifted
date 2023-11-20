#include <bits/stdc++.h>
#define N 1000
using namespace std;
const int dx[]={-1,0,1,0}, dy[]={0,1,0,-1};
int m,n, a[N+3][N+3], maxV, ans, s;
void Try(int u, int v)
{
    a[u][v]=2;
    s++;
    for (int k=0; k<4; k++)
    {
        int u1=u+dx[k];
        int v1=v+dy[k];
        if(a[u1][v1]==0)
            Try(u1,v1);
    }
}


int main()
{
    freopen("mlt.inp","r",stdin);
    freopen("mlt.out","w",stdout);
    cin>>m>>n;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin>>a[i][j];
    for (int i=1; i<=m; i++)
        a[i][0]=a[i][n+1]= '#';
    for (int i=1; i<=n; i++)
        a[0][i]=a[m+1][i]= '#';
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            if (a[i][j]==0)
            {
                ans++;
                s=0;
                Try(i,j);
                maxV=max(maxV,s);
            }
    cout<<ans<<'\n'<<maxV;
    return 0;
}
