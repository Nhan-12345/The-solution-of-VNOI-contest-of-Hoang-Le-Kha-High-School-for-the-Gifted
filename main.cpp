#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    freopen("bzero.inp","r",stdin);
    freopen("bzero.out","w",stdout);
    cin>>n;
    int s = 0;
    while (n>=5)
    {
        n=n/5;
        s+=n;
    }
    cout<<s;
    return 0;
}
