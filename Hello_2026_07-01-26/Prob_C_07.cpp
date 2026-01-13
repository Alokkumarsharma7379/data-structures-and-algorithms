#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if(!(cin >> t)) return 0;
    while (t--) {
        int64 n, m, k;
        cin >> n >> m >> k;
        int64 maxLeft = k - 1;
        int64 maxRight = n - k;
        int64 ans = 1; // at least base k

        // iterate possible L (number of fortified bases to the left)
        for (int64 L = 0; L <= maxLeft; ++L) {
            // Option A: R >= L  => constraint: L + 2R <= m+1  -> R <= floor((m+1-L)/2)
            int64 r1 = (m + 1 - L) / 2; // floor
            int64 rcand1 = -1;
            if (r1 >= L) {
                rcand1 = min(maxRight, r1);
            }
            // Option B: R < L  => constraint: 2L + R <= m+1 -> R <= m+1 - 2L, and R <= L-1
            int64 r2 = (m + 1 - 2 * L);
            int64 rcand2 = -1;
            if (r2 >= 0) {
                rcand2 = min<int64>({maxRight, r2, L - 1});
            }

            int64 Rmax = max(rcand1, rcand2);
            if (Rmax >= 0) {
                ans = max(ans, 1 + L + Rmax);
            }
        }

        if (ans > n) ans = n;
        cout << ans << '\n';
    }
    return 0;
}
