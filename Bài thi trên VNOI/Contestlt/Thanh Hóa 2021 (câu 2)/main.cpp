#include <bits/stdc++.h>
#define N int(1e6)
using namespace std;
vector<int>a(N+2), cnt(N+2);
int n, maxV, d;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen ("cau2.inp","r",stdin);
    freopen ("cau2.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    d=*max_element(cnt.begin(),cnt.end());
    cout<<d;
    return 0;
}
