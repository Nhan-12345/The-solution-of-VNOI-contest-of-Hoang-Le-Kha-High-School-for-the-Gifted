#include<bits/stdc++.h>
using namespace std;
int n, B;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen ("friend.inp","r",stdin);
    freopen ("friend.out","w",stdout);
    cin >> n >> B;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s.begin(), s.end());

    long long count = 0;
    for (int i = 0; i < n; i++) {
        int target = B - s[i];
        int left = i + 1, right = n;

        while (left < right) {
            int mid = (right + left) / 2;
            if (s[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }

        int upper = left;
        left = i + 1, right = n;
        while (left < right) {
            int mid = (right + left) / 2;
            if (s[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        count += upper - left;
    }
    cout << count;
    return 0;
}
