#include <bits/stdc++.h>
#define N int(1e4)
using namespace std;
int n, s, ant;
pair<int,int> a[N+2];
int main()
{
    freopen("dragon.inp","r",stdin);
    freopen("dragon.out","w",stdout);
    cin>>s>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        if (a[i].first>=s)
        {
            cout<<"NO"<<'\n';
            cout<<n-ant;
            return 0;
        }
        else
            s+=a[i].second;
            ant++;
    }
        cout<<"YES";
    return 0;
}
