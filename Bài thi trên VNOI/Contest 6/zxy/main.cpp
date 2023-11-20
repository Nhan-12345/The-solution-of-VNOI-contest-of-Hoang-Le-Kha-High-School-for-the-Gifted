#include <bits/stdc++.h>
#define N 15000
#define ll long long
using namespace std;
ll a[5*N+2], l, r;
int ans, n, k;
bool check(int x)
{
    int d=1, t=0;
    for (int i=1; i<=n; i++){
        if(t+a[i]>x)
        {
            d++;
            t=a[i];
        }
        else t+=a[i];
    }
    return (d<=k);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("zxy.inp","r",stdin);
    freopen("zxy.out","w",stdout);
    cin>>n>>k;
    for (int i=1; i<=n; i++){
         cin>>a[i];
         l=max(l,a[i]);
         r=r+a[i];
    }
    while (l<=r){
       int M=(l+r)/2;
        if(check(M)){
            ans=M;
            r=M-1;
        }
        else
            l=M+1;
    }
    cout<<ans;
    return 0;
}
