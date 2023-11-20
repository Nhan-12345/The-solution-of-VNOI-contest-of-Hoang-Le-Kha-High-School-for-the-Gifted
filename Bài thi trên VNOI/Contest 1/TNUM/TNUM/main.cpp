#include <bits/stdc++.h>
#define N int(1e5)
#define ll long long
using namespace std;
int p[N+3];
int n;
void snt()
{
    fill (p+2,p+N+1,1);
    for (int i=2; i*i<=N; i++)
        if (p[i]==1)
            for (int j=i*i; j<=N; j+=i) p[j]=0;
}
int main()
{
    snt();
    freopen ("tnum.inp","r",stdin);
    freopen ("tnum.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        ll k;
        cin>>k;
        ll s = sqrt(k);
        if (s*s==k&&p[s]==1)
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
    return 0;
}
