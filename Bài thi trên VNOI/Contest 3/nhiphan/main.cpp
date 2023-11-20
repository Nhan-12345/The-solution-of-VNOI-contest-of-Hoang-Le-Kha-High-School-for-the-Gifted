#include <bits/stdc++.h>

using namespace std;
int n, a[1001];
void xuly()
{
    for (int i=1; i<=n; i++)
        cout<<a[i];
    cout<<'\n';
}


void Try(int k)
{
    for (int i=0; i<=1; i++)
    {
        a[k]=i;
        if (k==n) xuly();
        else
            Try(k+1);
    }
}


int main()
{
    freopen ("nhiphan.inp","r",stdin);
    freopen ("nhiphan.out","w",stdout);
    cin>>n;
    Try(1);
}
