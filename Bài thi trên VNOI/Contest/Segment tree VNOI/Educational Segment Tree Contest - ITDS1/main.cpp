#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(long long i=a; i<=b; i++)

using namespace std;
const int N=1e5+2;
const int inf=1e18+2;
int n, q;
multiset<int> ST[N<<2];

void update(ll id, ll l, ll r, ll idx, ll val)
{
    if(idx<l||idx>r) return;
    if(l==r){
        ST[id].clear();
        ST[id].insert(val);
        return;
    }
    ll mid = ((l+r)>>1);
    update(id*2, l, mid, idx, val);
    update(id*2+1, mid+1, r, idx, val);
    ST[id].clear();
    ST[id].insert(max(ST[id*2], ST[id*2+1]));
    return;
}

ll gett(ll id, ll l, ll r, ll u, ll v, ll k)
{
    if(v<l||u>v) return -inf;
    if(u<=l&&v>=r){
        return *ST[id].begin();
    }
    ll mid = ((l+r)>>1);

}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n>>q;
    fort(i,1,n){
        int x;
        cin>>x;
        update(1,1,n,i,x);
    }
    ll type, u, v, k;
    while(q--){
        cin>>type;
        if(type==1){
            cin >> x >> v >> u;
            update(1,1,n,u,v);
        }
        else{
            cin >> u >> v >> k;
            cout << gett(1,1,n,u,v,k);
        }
    }
    return 0;
}
