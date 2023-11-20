#include <bits/stdc++.h>
#define N 15
using namespace std;
//-------------------------------------
int a[N+2], n, m;
vector<int>res,x;
//-------------------------------------
bool ok=false;
//-------------------------------------
void xuly()
{
    int s1=0,s2=0;
    for(int i =1;i<=n;i++)
    {
        if(x[i]==1)
            s1+=a[i];
        if(x[i]==2)
            s2+=a[i];
    }
    if(s1+m==s2)
    {
        res=x;
        ok=true;
    }
}
//-------------------------------------
void Try(int k)
{
    if(ok==true) return;
    for(int v=0;v<3;v++)
    {
        x[k]=v;
        if(k==n) xuly();
        else Try(k+1);
    }
}
//-------------------------------------
int main()
{
    freopen ("can.inp","r",stdin);
    freopen ("can.out","w",stdout);
    cin>>n>>m;
    x.resize(n+2);
    res.resize(n+2);
    a[1]=1;
    for(int i = 2;i<=n;i++)
        a[i]=a[i-1]*3;
    Try(1);
    int d=0;
    for(int i = 1;i<=n;i++)
        if(res[i]==1)
    {
         cout<<i<<" ";
        d++;
    }
         if(d==0)cout<<0;
                cout<<"\n";
    for(int i =1; i<=n; i++)
    {
        if(res[i]==2)
            cout << i << " ";
    }
    return 0;
}
//------------------------------------
