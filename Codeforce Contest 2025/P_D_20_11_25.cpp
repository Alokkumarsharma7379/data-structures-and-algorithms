#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];

        int mn = p[0];
        bool ok = true;

        for (int i = 1; i < n; i++) {
            if (p[i] < mn) {
                ok = false;
                break;
            }
            mn = min(mn, p[i]);
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
