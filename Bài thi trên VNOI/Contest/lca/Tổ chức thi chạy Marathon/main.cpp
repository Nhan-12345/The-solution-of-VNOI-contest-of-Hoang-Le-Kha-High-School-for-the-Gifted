#include <bits/stdc++.h>
#define ll long long
#define frt(i,a,b) for(int i=a; i<=b; i++)
#define frg(i,a,b) for(int i=a; i>=b; i--)

using namespace std;
const int N = 1e5 + 2;
int n, t, depth[N], T[N][17];
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
    frt(i, 1, 16)
        T[u][i] = T[T[u][i-1]][i-1];
    for(auto v : adj[u]){
        if(v == par) continue;
        dfs(v, u);
    }
}// dfs

int lca(int u, int v)
{
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

int dist(int u, int v)
{
    return (depth[u] + depth[v] - (depth[lca(u, v)] << 1));
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    init();

    //bfs;
    dfs(1, 0);
    int u, v, w;
    while(t--){
        cin >> u >> v >> w;
        if(dist(u, v) == dist(u, w) + dist(w, v))
            cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}
