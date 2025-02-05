#include <bits/stdc++.h>
#define ll long long
#define frt(i, a, b) for(int i=a; i<=b; i++)
#define frg(i, a, b) for(int i=a; i>=b; i--)

using namespace std;
const int N = 1e5 + 2;
int n, t, depth[N], T[N][17];
bool used[N];
vector<int> adj[N];

void init()
{
    cin >> n;
    frt(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> t;
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    depth[u] = 1;
    while(!q.empty()){
        u = q.front();
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

/** DÙNG DFS **/

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
}//DFS

int lca(int u, int v)
{
    if(depth[u] < depth[v]) swap(u, v);
    frg(i, 16, 0) //ha ve cung do xau
        if(depth[T[u][i]] >= depth[v])
            u = T[u][i];
    if(u == v) return u;
    frg(i, 16, 0) // ha ve lca
        if(T[u][i] != T[v][i]){
            u = T[u][i];
            v = T[v][i];
        }
    return T[u][0];
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    init();

    //bfs(1);
    dfs(1,0);
    int u, v;
    while(t--){
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
    return 0;
}
/**
7
6 1
6 4
4 7
3 4
1 2
2 5
6
3 3
7 7
1 3
5 7
7 6
2 4
**/
