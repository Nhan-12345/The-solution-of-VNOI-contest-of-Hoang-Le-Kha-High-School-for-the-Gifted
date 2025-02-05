#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define int long long
#define frt(i,a,b) for(int i=a; i<=b; i++)
#define frg(i,a,b) for(int i=a; i>=b; i--)
using namespace std;
const int oo = 1e9;
const int N = 1e6 + 2;
int n, a[N];


bool maximize(int& x, const int& y)
{
    if(x < y){
        x = y;
        return true;
    }
    else return false;
}

bool minimize(int& x, const int& y)
{
    if(x > y){
        x = y;
        return true;
    }
    else return false;
}

void init()
{
    cin >> n;
    frt(i,1,n) cin >> a[i];
}

namespace subtack1
{
    bool check()
    {
        return (n <= 1000);
    }

    void solve()
    {
        int ans = 0;
        frt(i, 1, n-1){
            int minn = oo, maxx = 0;
            frt(j, i, n){
                maximize(maxx, a[j]);
                minimize(minn, a[j]);
                ans += maxx - minn;
            }
        }
        cout << ans;
    }
}

namespace subtack2
{
    int maxL[N], maxR[N], minL[N], minR[N];
    bool check()
    {
        return (n > 1000 && n <= N);
    }


    void solve()
    {
        stack<int> st;
        a[0] = oo, a[n + 1] = oo;


        st.push(0);
        frt(i, 1, n){
            while(!st.empty() && a[st.top()] < a[i]){
                st.pop();
            }
            maxL[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();


        st.push(n + 1);
        frg(i ,n + 1, 1){
            while(!st.empty() && a[st.top()] < a[i])
                st.pop();
            maxR[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();


        a[0] = -oo, a[n + 1] = -oo;
        st.push(0);
        frt(i, 1, n){
            while(!st.empty() && a[st.top()] > a[i])
                st.pop();
            minL[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();


        st.push(n + 1);
        frg(i ,n + 1, 1){
            while(!st.empty() && a[st.top()] > a[i])
                st.pop();
            minR[i] = st.top();
            st.push(i);
        }

       int ans1 = 0, ans2 = 0, kq = 0;
       frt(i, 1, n){
           ans1 = (i - maxL[i]) * (maxR[i] - i);
           ans2 = (i - minL[i]) * (minR[i] - i);
           kq += (ans1 - ans2) * a[i];
//           cout << a[i] << ' ' << maxL[i] << ' ' << maxR[i] << '\n';
//           cout << ' ' << minL[i] << ' ' << minR[i] << '\n';
//           cout << '\n';
       }
       cout << kq;
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("bonus.inp", "r", stdin);
    freopen("bonus.out", "w", stdout);

    init();

    if(subtack1::check()) return subtack1::solve(), 0;
    if(subtack2::check()) return subtack2::solve(), 0;

}
