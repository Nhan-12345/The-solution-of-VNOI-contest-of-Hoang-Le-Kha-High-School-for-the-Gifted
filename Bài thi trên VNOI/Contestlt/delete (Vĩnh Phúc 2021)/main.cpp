#include <bits/stdc++.h>
#define N int(1e6)
#define ll long long
using namespace std;
const int K=1e9+7;
vector<ll>a(N+2), c1(N+2), c3(N+2);
int n;
ll res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen ("delete.inp","r",stdin);
    freopen ("delete.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>a[i];
        if (a[i]==1) c1[i] = c1[i-1]+1;
        else c1[i] = c1[i-1];
    }
    for (int i=n; i>0; i--)
        if (a[i]==3)
            c3[i]=c3[i+1]+1;
        else
            c3[i]=c3[i+1];
    int x =0;
    for (int i=1; i<=n; i++)
    if (a[i]==2){
        c1[i]=(c1[i]+c1[x])%K;
        res = (res + (c1[i]*c3[i])%K)%K;
        c1[i]=(c1[i]+c1[x])%K;
        x=i;
    }
    cout<<res;
    return 0;
}
