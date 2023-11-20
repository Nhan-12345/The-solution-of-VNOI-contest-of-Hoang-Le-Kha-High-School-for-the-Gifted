#include <bits/stdc++.h>
#define N 1000
using namespace std;
const int inf = 1e9+2;
int n, xmin=inf ,ymin=inf, xmax=-inf, ymax=-inf;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen ("square.inp","r",stdin);
    freopen ("square.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++){
        int x, y;
        cin>>x>>y;
        xmax=max(xmax,x);
        ymax=max(ymax,y);
        xmin=min(xmin,x);
        ymin=min(xmin,y);
    }
    int d =max(xmax-xmin,ymax-ymin);
    cout<<d*d;
    return 0;
}
