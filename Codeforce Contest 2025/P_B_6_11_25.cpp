#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        sort(v.begin(), v.end());
        bool found = false;

        for (int i = 0; i < n && !found; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((v[j] % v[i]) % 2 == 0) {
                    cout << v[i] << ' ' << v[j] << '\n';
                    found = true;
                    break;           // exit inner loop only
                }
            }
        }

        if (!found) cout << -1 << '\n';
    }
    return 0;
}
