#include <bits/stdc++.h>
#define N 10000000
#define pii pair<ll,ll>
#define ll long long
using namespace std;
pii a[N+2];
ll n, d, maxV=-1e9, sum;
//---------------------------------------
bool cmp(pii X,pii Y)
{
    return X.first<Y.first;
}
//---------------------------------------
int main()
{
    freopen ("cow.inp","r",stdin);
    freopen ("cow.out","w",stdout);
    cin>>n>>d;
    for (int i=1; i<=n; i++)
        cin>>a[i].first>>a[i].second;
    sort (a+1,a+n+1,cmp);
    ll L=1 , R=1;
    while (L<=R&&R<=n){
        if (a[R].first-a[L].first<=d){
            sum+=a[R++].second;
            maxV=max(maxV,sum);
        }
        else
            sum-=a[L++].second;
    }
    cout<<maxV;
    return 0;
}
