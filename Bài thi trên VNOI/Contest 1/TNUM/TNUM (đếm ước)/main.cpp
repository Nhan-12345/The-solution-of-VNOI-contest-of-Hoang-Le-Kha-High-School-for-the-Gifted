#include <bits/stdc++.h>
#define ll long long
#define N 10000000
using namespace std;
int a[N+3];
ll n;
int demUoc(int x)
{
    int s = 1;
    for (int i=2; i*i<=x; i++)
        if (x%i==0)
    {
        int k = 0;
        while (x%i==0)
        {
            k++;
            n=n/i;
        }
        s = s*(k+1);
    }
    if (x>1)
        s = s*2;
    return s;
}
int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n;i++)
        if (demUoc(a[i])==3)
            cout<<"YES";'\n';

    return 0;
}
