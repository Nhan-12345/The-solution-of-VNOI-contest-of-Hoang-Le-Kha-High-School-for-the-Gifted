#include <bits/stdc++.h>
#define N int(1e5)
#define ll long long
using namespace std;
ll n, a[5*N+2], ans, k, M;
bool check(int x)
{
    int s=0;
    for (int i=1; i<=x; i++){
        s+=a[i];
        if (s>=k) return true;
    }
    for (int i=x+1; i<=n; i++){
        s=s-a[i-x]+a[i];
        if(s>=k) return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("sub.inp","r",stdin);
    freopen("sub.out","w",stdout);
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int l=1, r=n;
    while (l<=r){
        M=(l+r)/2;
        if(check(M)==true){
            ans=M;
            r=M-1;
        }
        else
            l=M+1;
    }
    cout<<ans;
    return 0;
}
