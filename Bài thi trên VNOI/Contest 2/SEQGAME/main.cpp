#include <bits/stdc++.h>
#define N int(1e5)
#define M int(2e9)
using namespace std;
int a[N+3], b[N+3];
int n, ans=M;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=n; i++)
        cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int i=1, j=n;
    while(i<=n&&j>=1)
    {
        if (a[i]+b[j]==0)
        {
            ans=0;
            break;
        }
        ans=min(ans,abs(a[i]+b[j]));
        if (a[i]+b[j]>0) j--;
        else i++;
    }
    cout<<ans;
    return 0;
}
