#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> alok(n + 1), sharma(n + 1);
        for (int i = 1; i <= n; ++i) cin >> alok[i];
        for (int i = 1; i <= n; ++i) cin >> sharma[i];
        int L = n - k + 1;
        int R = k;
        vector<int> kumar(n + 1, 0);
        for (int i = max(1, L); i <= min(n, R); ++i) {
            kumar[alok[i]] = 1;
        }
        bool ok = true;
        vector<int> used(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (i < L || i > R) {
                if (sharma[i] != -1 && sharma[i] != alok[i]) {
                    ok = false;
                }
            } else {
                if (sharma[i] != -1) {
                    if (sharma[i] < 1 || sharma[i] > n || !kumar[sharma[i]]) ok = false;
                    if (used[sharma[i]]) ok = false;
                    used[sharma[i]] = 1;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}