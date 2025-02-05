#include <bits/stdc++.h>
#define ll long long
#define frt(i, a, b) for(int i=a; i<=b; i++)
#define frg(i, a, b) for(int i=a; i>=b; i--)

using namespace std;
const int N = 1e5;
int n, t, depth[N], T[N][20], ST[N<<2];
bool used[N];
vector<int> adj[N];

void init()
{
    cin >> n >> t;
    frt(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs()
{
    queue<int> q;
    q.push(1);
    depth[1] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(!used[u]){
            used[u] = true;
            for(auto v : adj[u]){
                if(v == T[u][0]) continue;
                T[v][0] = u;
                depth[v] = depth[u] + 1;
                frt(i, 1, 16)
                    T[v][i] = T[T[v][i-1]][i-1];
                q.push(v);
            }
        }
    }
}

/** DFS **/
void dfs(int u, int par)
{
    depth[u] = depth[par] + 1;
    T[u][0] = par;
    frt(i, 1, 17)
        T[u][i] = T[T[u][i-1]][i-1];
    for(auto v : adj[u]){
        if(v == par) continue;
        dfs(v, u);
    }
}// dfs

int lca(int u, int v)
{
    if(u < 1) return v;
    if(v < 1) return u;
    if(depth[u] < depth[v]) swap(u, v);
    frg(i, 16, 0)
        if(depth[T[u][i]] >= depth[v])
            u = T[u][i];
    if(u == v) return u;
    frg(i, 16, 0)
        if(T[u][i] != T[v][i])
            u = T[u][i], v = T[v][i];
    return T[u][0];
}

void update(int id, int l, int r, int idx, int val)
{
    if(idx < l || idx > r) return;
    if(l == r){
        ST[id] = val;
        return;
    }
    int mid = (l + r) /2;
    update(idx * 2, l, mid, idx, val);
    update(idx * 2 + 1, mid+1, r, idx, val);
    ST[id] = lca(ST[id * 2], ST[id * 2 + 1]);
    return;
}

int gett(int id, int l, int r, int u, int v)
{
    if(v < l || u > r) return 0;
    if(u <= l && v >= r)
        return ST[id];
    int mid = (l + r) /2;
    int x = gett(id * 2, l, mid, u, v);
    int y = gett(id * 2 + 1, mid + 1, r, u, v);
    return lca(x, y);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    init();

    //bfs();
    dfs(1,0);
    frt(i, 1, n)
        update(1, 1, n, i, i);
    int u, v;
    while (t--){
        cin >> u >> v;
        if(u > v) swap(u, v);
        cout << gett(1, 1, n, u, v) << '\n';
    }
    return 0;
}

/**
5 3
1 2
2 3
3 4
3 5
2 5
1 3
4 5
**/
