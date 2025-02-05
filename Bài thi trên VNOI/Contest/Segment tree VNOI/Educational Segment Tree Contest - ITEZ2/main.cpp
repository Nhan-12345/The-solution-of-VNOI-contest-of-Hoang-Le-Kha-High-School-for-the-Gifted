#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(long long i=a; i<=b; i++)

using namespace std;
const int N = 1e5+2;
const int inf = 1e9+2;
ll n, q, ST[N<<2];

void update(ll id, ll l, ll r, ll idx, ll val)
{
    if(idx<l||idx>r) return;
    if(l==r){
        ST[id] = val;
        return;
    }
    ll mid = ((l + r) >> 1);
    update(id*2,l,mid,idx,val);
    update(id*2+1,mid+1,r,idx,val);
    ST[id] = ST[id*2] + ST[id*2+1];
    return;
}

ll gett(ll id, ll l, ll r, ll u, ll v)
{
    if(v<l||u>r) return 0;
    if(u<=l&&v>=r) return ST[id];
    ll mid = ((l + r) >> 1);
    return gett(id*2,l,mid,u,v) + gett(id*2+1,mid+1,r,u,v);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n>>q;
    ll typle, u, v;
    while(q--){
        cin>>typle>>u>>v;
        if(typle == 1) update(1,1,n,u,v);
        else cout<<gett(1,1,n,u,v)<<'\n';
    }
    return 0;
}
