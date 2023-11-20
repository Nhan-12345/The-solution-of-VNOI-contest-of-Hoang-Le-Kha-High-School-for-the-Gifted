#include <bits/stdc++.h>
#define N int(1e5)
using namespace std;
int n, a[N+3], ant;

bool check(string s)
{
    while (s.find("()") != string::npos)
    {
        int k = s.find("()");
        s.erase(k,2);
    }
    return (s == "");
}


void mang()
{
    string s="";
    for (int i=1; i<=n; i++)
    {
        if (a[i]==0) s.push_back('(');
        else s.push_back(')');
    }
    if (check(s))
    {
        cout<<s<<'\n';
        ant++;
    }
}


void Try(int k)
{
    for (int i=0; i<=1;i++)
    {
        a[k]=i;
        if (k==n) mang();
        else Try(k+1);
    }
}


int main()
{
    freopen("ngoac.inp","r",stdin);
    freopen("ngoac.out","w",stdout);
    cin>>n;
    Try(1);
    cout<<ant;
    return 0;
}
