#include <bits/stdc++.h>
#define N int(1e8)
using namespace std;
int n, minV, res=1e9;
long long s, a[N+2], sum;
int main()
{
    freopen ("wood.inp","r",stdin);
    freopen ("wood.out","w",stdout);
    cin>>n>>s;
    for (int i=1; i<=n; i++) cin>>a[i];
    sort (a+1,a+n+1,greater<int>());
    int L=1, R;
    for (R=1; R<=n; R++){
        sum+=a[R];
        if (sum>=s){
        minV=min(res,R-L+1);
        L++
        }
    }
    cout<<minV;
    return 0;
}
