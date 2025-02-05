#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(long long i=a; i<=b; i++)
using namespace std;
const int N=1e5+2;
const int inf=1e18+2;
ll n, q, ST[N<<2];

void update(ll id, ll l, ll r, ll idx, ll idy, ll val)
{
    if(idy<l||idx>r) return;
    if(l==r){
        ST[id] += val;
        return;
    }
    ll mid = ((l+r)>>1);
    update(id*2,l,mid,idx,idy,val);
    update(id*2+1,mid+1,r,idx,idy,val);
    ST[id] = max(ST[id*2], ST[id*2+1]);
    return;
}

ll gett(ll id, ll l, ll r, ll u, ll v)
{
    if(v<l||u>r) return -inf;
    if(u<=l&&v>=r) return ST[id];
    ll mid = ((l+r)>>1);
    return max(gett(id*2,l,mid,u,v), gett(id*2+1,mid+1,r,u,v));
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n;
    fort(i,1,n){
        ll x;
        cin>>x;
        update(1,1,n,i,i,x);
    }
    cin>>q;
    ll typle, x, y, val;
    while(q--){
        cin>>typle;
        if(typle==1){
            cin>>x>>y>>val;
            update(1,1,n,x,y,val);
        }
        else{
            cin>>x>>y;
            cout<<gett(1,1,n,x,y)<<'\n';
        }
    }
    return 0;
}
