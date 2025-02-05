#include <bits/stdc++.h>
#define ll long long
#define frt(i, a, b) for (int i = a; i <= b; i++)
#define frg(i, a, b) for (int i = a; i >= b; i--)

using namespace std;
const int N = 1e5 + 2;
int m, n, kq[N];

struct Furina
{
    int x, loai, id;
};
vector<Furina> a;

bool cmp(const Furina &X, const Furina &Y)
{
    if(X.x == Y.x) return X.loai > Y.loai;
    return X.x < Y.x;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("overload.inp", "r", stdin);
    freopen("overload.out", "w", stdout);
    cin >> n >> m;

    frt(i, 1, n) {
        int k;
        cin >> k;
        a.push_back({k, 1, i});

    }

    frt(i, 1, m) {
        int k;
        cin >> k;
        a.push_back({k, 0, i});
    }

    sort(a.begin(), a.end(), cmp);
//    for (auto c : a)
//        cout << c.x << ' ' << c.loai << ' ' << c.id << '\n';

    stack<int> st;
    for(int i = a.size()-1; i >= 0; i--) {
        if(!a[i].loai)
            st.push(a[i].id);
        else{
            if (!st.empty()){
                kq[a[i].id] = st.top();
                st.pop();
            }
            else kq[a[i].id] = -1;
        }
    }

    frt(i, 1, n)
        cout << kq[i] << '\n';
    return 0;
}
