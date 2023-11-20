#include <bits/stdc++.h>
#define N 15
using namespace std;


int a[N+2][N+2];
int tx[]={-1,0,1,0};
int ty[]={0,1,0,-1};
vector<int>x, y, Tamx, Tamy;
int lmin=225, u, v, m, n;


void Try(int u, int v, int d)
{
    a[u][v]=2;
    Tamx[d]=u;
    Tamy[d]=v;
    if (u==1||u==m||v==1||v==n)
    {
        if(lmin>d)
        {
        lmin=d;
        x=Tamx;
        y=Tamy;
        }
    return;
    }
    for (int k=0; k<4; k++)
    {
        int u1=u+tx[k];
        int v1=v+ty[k];
        if (a[u1][v1]==0)
        {
            Try(u1,v1,d+1);
            a[u1][v1]=0;
        }
    }
}


int main()
{
    freopen("maze.inp","r",stdin);
    freopen("maze.out","w",stdout);
    cin>>m>>n;
    for (int i=1; i<=m; i++)
    for (int j=1; j<=n; j++)
        cin>>a[i][j];
    cin>>u>>v;
    Tamx.resize(225);
    Tamy.resize(225);
    Try(u,v,0);
    if(lmin==225)
        cout<<-1;
    else
    {
        cout<<lmin<<'\n';
        for (int i=1; i<=lmin; i++)
            cout<<x[i]<<" "<<y[i]<<'\n';
    }
    return 0;
}
