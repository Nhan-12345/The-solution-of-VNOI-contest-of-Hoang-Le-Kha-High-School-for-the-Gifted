#include <bits/stdc++.h>
using namespace std;
int n;
bool ngto(int k)
{
    if (k<2) return false;
    for (int i=2; i*i<=k; i++)
    if (k%i==0) return false;
    return true;
}
int daonguoc(int x)
{
    int s = 0;
    while (x>0)
    {
        int r=x%10;
        s = s*10+r;
        x=x/10;
    }
        return s;
}
int main()
{
    //freopen ("cprime.inp","r",stdin);
    //freopen ("cprime.out","w",stdout);
    cin>>n;
    if (ngto(n)&&ngto(daonguoc(n)))
        cout<<1;
    else
        cout<<0;
    return 0;
}
