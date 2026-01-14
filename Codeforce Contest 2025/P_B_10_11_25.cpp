#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) cin >> p[i];

        string x;
        cin >> x;
        x = ' ' + x; // 1-indexed

        // Case 1: no need
        bool hasOne = false;
        for (int i = 1; i <= n; i++)
            if (x[i] == '1') hasOne = true;
        if (!hasOne) {
            cout << 0 << "\n";
            continue;
        }

        // Find leftmost and rightmost 1 in x
        int L = -1, R = -1;
        for (int i = 1; i <= n; i++)
            if (x[i] == '1') { L = i; break; }
        for (int i = n; i >= 1; i--)
            if (x[i] == '1') { R = i; break; }

        int mn = INT_MAX, mx = INT_MIN;
        for (int i = L; i <= R; i++) {
            mn = min(mn, p[i]);
            mx = max(mx, p[i]);
        }

        int li = -1, ri = -1;
        for (int i = 1; i <= n; i++) {
            if (p[i] == mn) li = i;
            if (p[i] == mx) ri = i;
        }

        if (li == -1 || ri == -1) {
            cout << "-1\n";
            continue;
        }

        if (li > ri) swap(li, ri);

        // Check if this single operation can cover all x[i] = 1
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (x[i] == '1') {
                if (!(mn < p[i] && p[i] < mx)) {
                    ok = false;
                    break;
                }
            }
        }

        if (!ok) {
            cout << "-1\n";
        } else {
            cout << 1 << "\n";
            cout << li << " " << ri << "\n";
        }
    }
    return 0;
}
