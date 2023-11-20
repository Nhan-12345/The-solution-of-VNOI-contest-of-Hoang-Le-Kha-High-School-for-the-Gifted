#include <bits/stdc++.h>
using namespace std;

int tongchuso(int a)
{
    int j=0;
    while (a>0)
    {
        int r=a%10;
        j+=r;
        a/=10;
    }
    return j;
}

bool tonguoc(int k)
{
    int s=0;
    for (int i=1; i<k; i++)
    {
        if (k%i==0)
         s+=i;
    }
    if (s!=k) return 0;
    return 1;
}

int n, ans;

int main()
{
    freopen ("bhhao.inp","r",stdin);
    freopen ("bhhao.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            int x;
            cin>>x;
            if (tonguoc(tongchuso(x)))
                ans++;
        }
    cout<<ans;
    return 0;
}
