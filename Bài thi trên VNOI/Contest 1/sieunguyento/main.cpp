#include <bits/stdc++.h>
#define N int(1e7)
using namespace std;
int p[N+3];
int a, b;
void snt(int k)
{
    fill (p+2,p+k+1,1);
    for (int i = 2; i*i<=k; i++)
        if (p[i]==1)
            for (int j=i*i; j<=k; j+=i)
                p[j]=0;
}
bool sieunt(int x)
{
    while (x>0)
    {
        if (p[x]==0) return false;
        x=x/10;
    }
    return true;
}
int main()
{
    freopen ("sprime.inp","r",stdin);
    freopen ("sprime.out","w",stdout);
    cin>>a>>b;
    snt(b);
    for (int x=a; x<=b; x++)
        if (sieunt(x))
    cout<<x<<'\n';
    return 0;
}
