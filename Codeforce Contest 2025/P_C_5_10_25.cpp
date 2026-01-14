#include <bits/stdc++.h>
using namespace std;

const long long MOD = 676767677;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        if (n == 1) {
            // Single wizard → always 2 ways: left or right
            cout << 2 % MOD << "\n";
            continue;
        }

        vector<int> s(n - 1);
        bool invalid = false;

        // Step 1: compute s_i = a[i+1] - a[i] + 1
        for (int i = 0; i < n - 1; ++i) {
            long long val = a[i + 1] - a[i] + 1;
            if (val < 0 || val > 2) {  // impossible
                invalid = true;
                break;
            }
            s[i] = (int)val;
        }

        if (invalid) {
            cout << 0 << "\n";
            continue;
        }

        long long ans = 0;

        // Step 2: try L1 = 0 and L1 = 1
        for (int L1 = 0; L1 <= 1; ++L1) {
            vector<int> L(n);
            L[0] = L1;
            bool ok = true;

            for (int i = 0; i < n - 1; ++i) {
                L[i + 1] = s[i] - L[i];
                if (L[i + 1] < 0 || L[i + 1] > 1) {
                    ok = false;
                    break;
                }
            }

            if (!ok) continue;

            int sumL = accumulate(L.begin(), L.end(), 0);
            long long rhs = n + L1 - a[0];
            if (sumL == rhs) ans++;
        }

        cout << (ans % MOD) << "\n";
    }

    return 0;
}
