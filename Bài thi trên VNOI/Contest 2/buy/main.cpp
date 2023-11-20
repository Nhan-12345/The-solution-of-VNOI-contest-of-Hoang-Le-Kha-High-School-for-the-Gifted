#include <bits/stdc++.h>
#define N 100000
using namespace std;
struct cuahang
{
    int a, b, id;
};
cuahang A[N+3];

bool cmd(cuahang X, cuahang Y)
{
    return X.b < Y.b;
}

int m, n, ans, x[N+3];

int main()
{
    freopen ("buy.inp","r",stdin);
    freopen ("buy.out","w",stdout);
    cin>>m>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>A[i].a>>A[i].b;
        A[i].id = i;
    }
    sort (A+1,A+n+1,cmd);
    int cnt = 0, k;
    for (int i=1; i<=n; i++)
    {
        if (cnt+A[i].a > m)
        {
            k=i;
        break;
        }
        cnt += A[i].a;
        ans += A[i].a * A[i].b;
        x[A[i].id]=A[i].a;
    }
    ans += (m-cnt) * A[k].b;
    x[A[k].id]=m-cnt;
    cout<<ans<<'\n';
    for (int i=1; i<=n; i++)
        cout<<x[i]<<'\n';
    return 0;
}
