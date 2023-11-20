#include <bits/stdc++.h>

using namespace std;
int n;
int demUoc(int x)
{
    int  d=1;
    for (int i=2; i<=x; i++)
    if (x%i==0)
    {
        int s=0;
        while (x%i==0)
        {
            s++;
            x/=i;
        }
        d=d*(x+1);
    }
    if (x>1) d=d*2;
    return d;
}
int main()
{
    cin>>n;
    cout<<demUoc(n);
    return 0;
}
