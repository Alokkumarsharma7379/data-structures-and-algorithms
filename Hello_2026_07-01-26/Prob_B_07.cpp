#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // compute mex of the whole array
        vector<char> seen(n + 5, 0);
        for (int x : a) {
            if (x >= 0 && x <= n) seen[x] = 1;
        }
        int mex = 0;
        while (seen[mex]) ++mex;

        int ans = min(k - 1, mex);
        cout << ans << '\n';
    }
    return 0;
}
