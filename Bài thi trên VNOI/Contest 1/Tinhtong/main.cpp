#include <bits/stdc++.h>
using namespace std;
int n, a[1000];
int main()
{
    freopen("mang.inp","r",stdin);
    freopen("mang.out","w",stdout);
    int S=0;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
          cout<<a[i]<<" "<<'\n';
        {
        for (int i=1; i<=n; i++)
        if (a[i]%2==0)
            S=S+a[i];
            cout<<"Tong cua cac so chan la: "<<S<<'\n';
        }
{
    int D=0;
    for (int i=1; i<=n; i++)
        if(a[i]%2==0)
            D+=1;
            cout<<"So cac so chan trog mang la: "<<D;
}
    return 0;
}
