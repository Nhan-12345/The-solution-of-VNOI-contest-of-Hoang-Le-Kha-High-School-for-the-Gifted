#include <bits/stdc++.h>

using namespace std;
int n, a[1001];
int cheoxuoi[1001]={0}, cheonguoc[1001]={0}, cot[1001]={0};

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
        if (!cot[i] && !cheoxuoi[k-i+n] && !cheonguoc[k+i-1])
        {
            a[k]=i;
            cot[i] = cheoxuoi[k-i+n] = cheonguoc[k+i-1]=1;
            if (k==n)
                mang();
            else
                Try(k+1);
            cot[i] = cheoxuoi[k-i+n] = cheonguoc[k+i-1]=0;
        }
    }
}


int main()
{
    freopen ("queen.inp","r",stdin);
    freopen ("queen.out","w",stdout);
    cin>>n;
    Try(1);
}
