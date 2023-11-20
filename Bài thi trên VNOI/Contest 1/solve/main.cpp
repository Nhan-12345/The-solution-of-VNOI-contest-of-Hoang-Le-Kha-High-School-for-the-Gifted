#include <bits/stdc++.h>
#define ll long long
#define N 20000000
using namespace std;
ll n, y=N;
ll S(ll x);
{
    ll s=0;
    while (x>0)
    {
        s+=x%10;
        x=x/10;
    }
    return s;
}
int main()
{
    cin>>n;
    for(ll t; t<=81; t++)
    {
        ll x=(-t+sqrt(t*t+4*4))/2;
        if (x*x+S(x)*x-n==0)
            y=min(y,x);
    }
    if (y==N)
        cout<<-1;
    else
        cout<<y;
    return 0;
}
