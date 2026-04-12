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
        vector<int> kumar(n + 1, 0);
        vector<int> need(n + 1, 0);
        bool ok = true;
        for (int start = 1; start <= k; ++start) {
            bool constant_class = true;
            int base = alok[start];
            for (int j = start + k; j <= n; j += k) {
                if (alok[j] != base) {
                    constant_class = false;
                    break;
                }
            }
            if (!constant_class) {
                for (int j = start; j <= n; j += k) {
                    if (sharma[j] != -1 && sharma[j] != alok[j]) {
                        ok = false;
                    }
                }
            } else {
                kumar[base]++;
                int fixed_value = -1;
                for (int j = start; j <= n; j += k) {
                    if (sharma[j] != -1) {
                        if (fixed_value == -1) fixed_value = sharma[j];
                        else if (fixed_value != sharma[j]) ok = false;
                    }
                }
                if (fixed_value != -1) {
                    need[fixed_value]++;
                }
            }
        }
        for (int v = 1; v <= n; ++v) {
            if (need[v] > kumar[v]) ok = false;
        }
        cout << (ok ? "YES" : "NO") <<endl;
    }
    return 0;
}