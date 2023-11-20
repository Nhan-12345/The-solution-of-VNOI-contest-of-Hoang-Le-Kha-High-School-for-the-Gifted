#include <bits/stdc++.h>

using namespace std;
int K[1001]={0};
int a[1001], n;
void mang()
{
    for (int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<'\n';
}
void Try(int k)
{
    for (int i=1; i<=n; i++)
    {
        if (!K[i])
        {
            a[k]=i;
            K[i]=1;
            if (k==n) mang();
            else
                Try(k+1);
            K[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    Try(1);
    return 0;
}
