#include <bits/stdc++.h>
using namespace std;
int n, ans, S, dem_i, dem_j;
int main()
{
    freopen ("ddelete.inp","r",stdin);
    freopen ("ddelete.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        S+=x;
        if (x%2==0)
            dem_i++;
        else
            dem_j++;
    }
    if (S%2==0)
        ans=dem_i*(dem_i-1)/2+dem_j*(dem_j-1)/2;
    else
        ans=dem_i*dem_j;
    cout<<ans;
    return 0;
}
