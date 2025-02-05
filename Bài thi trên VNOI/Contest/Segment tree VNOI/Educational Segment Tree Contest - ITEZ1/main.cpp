#include <bits/stdc++.h>
#define ll long long
#define getbit(x,k) ((x>>k)&1)
#define fort(i,a,b) for(long long i=a; i<=b; i++)

using namespace std;
const int N=1e5+2;
const int inf=1e9+1e12;
ll n, ST[N<<2];

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
    ST[id] = max(ST[id*2], ST[id*2+1]);
    return;
}

ll gett(ll id, ll l, ll r, ll u, ll v)
{
    if(v<l || u>r) return -inf;
    if(u<=l && v>=r) return ST[id];
    ll mid = ((l + r) >> 1);
    return max(gett(id*2, l, mid, u, v), gett(id*2+1, mid+1, r, u, v));
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    fort(i,1,n){
        ll x;
        cin >> x;
        update(1,1,n,i,x);
    }
    ll q, typle, x, y;
    cin>>q;
    while(q--){
        cin>>typle>>x>>y;
        if(typle == 1) update(1,1,n,x,y);
        else cout<<gett(1,1,n,x,y)<<'\n';
    }
    return 0;
}
