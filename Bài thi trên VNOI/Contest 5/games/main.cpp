#include <bits/stdc++.h>
#define N 1000
using namespace std;
int n, s, maxV, a[N+2][N+2], ud[N+2], x[N+2];
//----------------------------------------
void mang()
{
    for (int i=1; i<=n; i++)
    s+=a[x[i]][i];
    maxV=max(maxV,s);
    for (int i=1; i<=n; i++)
    s-=a[x[i]][i];
}
//----------------------------------------
void Try (int k)
{
    for (int i=1; i<=n; i++)
    if (ud[i]==0){
        x[k]=i;
        ud[i]=1;
    if (k==n) mang();
    else Try(k+1);
    ud[i]=0;
    }
}
//----------------------------------------
int main()
{
    freopen ("games.inp","r",stdin);
    freopen ("games.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin>>a[i][j];
    Try(1);
    cout<<maxV;
    return 0;
}
