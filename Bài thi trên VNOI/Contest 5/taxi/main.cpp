#include <bits/stdc++.h>
#define N int(1e5)
using namespace std;
int n, ans, c[N+2];
int main()
{
    freopen("taxi.inp","r",stdin);
    freopen("taxi.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        c[x]++;
    }
    ans=c[4];
    if(c[3]<=c[1])
    {
        ans+=c[3];
        c[1]-=c[3];
        ans+=(c[2]/2);
        if(c[2]%2==0)
            ans+=(c[1]+3)/4;
        else
        {
            ans+=1;
            c[1]=max(0,c[1]-2);
            ans+=(c[1]+3)/4;
        }
        cout<<ans;
    }
    else
    {
        ans+=c[1];
        c[3]-=c[1];
        ans+=((c[2]+1)/2);
        ans+=c[3];
        cout<<ans;
    }
    return 0;
}
