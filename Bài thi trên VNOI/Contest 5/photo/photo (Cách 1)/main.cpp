#include <bits/stdc++.h>
#define N 100000
#define pii pair <int,int>
#define f first
#define s second
using namespace std;
const int Mx = 1e9+2;
pii a[N+2];
long long n, sum=Mx, ans, c[N+2];
int main()
{
    freopen ("photo.inp","r",stdin);
    freopen ("photo.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i].f>>a[i].s;
    int L=1,R=1;
    c[a[R].s]++;
    while (L<=R&&R<=n){
        if (c[a[L].s]>1){
            c[a[L].s]--;
            L++;
        }
        else{
            ans=a[R].f-a[L].f;
            if (c[1]>0&&c[2]>0&&c[3]>0)
                sum=min(sum,ans);
            R++;
            c[a[R].s]++;
        }
    }
    cout<<sum;
    return 0;
}
