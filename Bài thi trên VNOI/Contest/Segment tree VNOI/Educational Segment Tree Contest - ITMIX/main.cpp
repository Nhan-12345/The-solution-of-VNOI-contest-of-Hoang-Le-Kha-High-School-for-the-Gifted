#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(long long i=a; i<=b; i++)
#define forg(i,a,b) for(long long i=a; i>=b; i--)

using namespace std;
const int N = 1e5 + 2;
const int mod = 1e9 + 7;
int n, q, ST[N << 2];

void build(ll id, ll l, ll r, ll idx, ll val)
{
	if (idx<l || idx>r) return;
	if (l == r) {
		ST[id] = val;
		return;
	}
	ll mid = ((l + r) >> 1);
	build(id * 2, l, mid, idx, val);
	build(id * 2 + 1, mid + 1, r, idx, val);
	ST[id] = ST[id * 2] + ST[id * 2 + 1];
	return;
}

void update1(ll id, ll l, ll r, ll idx, ll idy, ll val)
{
	if (idy<l || idx>r) return;
	if (l == r) {
		ST[id] += val;
		return;
	}
	ll mid = ((l + r) >> 1);
	update1(id * 2, l, mid, idx, idy, val);
	update1(id * 2 + 1, mid + 1, r, idx, idy, val);
	ST[id] = ST[id * 2] + ST[id * 2 + 1];
	return;
}

void update2(ll id, ll l, ll r, ll idx, ll idy, ll val)
{
	if (idy<l || idx>r) return;
	if (l == r) {
		ST[id] *= val;
		return;
	}
	ll mid = ((l + r) >> 1);
	update2(id * 2, l, mid, idx, idy, val);
	update2(id * 2 + 1, mid + 1, r, idx, idy, val);
	ST[id] = ST[id * 2] + ST[id * 2 + 1];
	return;
}

void update3(ll id, ll l, ll r, ll idx, ll idy, ll val)
{
	if (idy<l || idx>r) return;
	if (l == r) {
		ST[id] = val;
		return;
	}
	ll mid = ((l + r) >> 1);
	update3(id * 2, l, mid, idx, idy, val);
	update3(id * 2 + 1, mid + 1, r, idx, idy, val);
	ST[id] = ST[id * 2] + ST[id * 2 + 1];
	return;
}

ll query(ll id, ll l, ll r, ll u, ll v)
{
	if (v<l || u>r) return 0;
	if (u <= l && v >= r) return ST[id];
	ll mid = ((l + r) >> 1);
	return ((query(id * 2, l, mid, u, v) % mod) + (query(id * 2 + 1, mid + 1, r, u, v) % mod)) % mod;
	//return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;
	fort(i, 1, n) {
		ll x;
		cin >> x;
		build(1, 1, n, i, x);
	}
	ll type, u, v, x;
	while (q--) {
		cin >> type >> u >> v;
		if (type == 1) {
			cin >> x;
			update1(1, 1, n, u, v, x);
		}

		if (type == 2) {
			cin >> x;
			update2(1, 1, n, u, v, x);
		}

		if (type == 3) {
			cin >> x;
			update3(1, 1, n, u, v, x);
		}

		if (type == 4) cout << query(1, 1, n, u, v) << '\n';
	}
	return 0;
}