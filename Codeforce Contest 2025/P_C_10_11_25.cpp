#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        vector<int> top(n+1), bottom(n+1);
        for (int i = 1; i <= n; ++i) cin >> top[i];
        for (int i = 1; i <= n; ++i) cin >> bottom[i];

        int V = 2 * n;
        // occurrences of each value v: list of (row, col)
        vector<vector<pii>> occ(V + 1);
        for (int c = 1; c <= n; ++c) occ[top[c]].push_back({1, c});
        for (int c = 1; c <= n; ++c) occ[bottom[c]].push_back({2, c});

        // current coverage arrays for columns
        vector<int> topCov(n+1, 0), bottomCov(n+1, 0);

        // sets of columns still uncovered (value 0)
        set<int> topZero, bottomZero;
        for (int c = 1; c <= n; ++c) {
            topZero.insert(c);
            bottomZero.insert(c);
        }

        long long ans = 0;
        int r = 0; // current window is values [l..r], start empty
        for (int l = 1; l <= V; ++l) {
            // expand r until condition satisfied or r == V
            while (r < V) {
                // compute prefTop and suffBottom for current window
                int firstZeroTop = topZero.empty() ? (n+1) : *topZero.begin();
                int lastZeroBottom = bottomZero.empty() ? 0 : *bottomZero.rbegin();
                int prefTop = firstZeroTop - 1;
                int suffBottom = lastZeroBottom + 1;
                if (prefTop >= suffBottom) break; // satisfied already
                // else include value r+1
                ++r;
                for (auto &p : occ[r]) {
                    int row = p.first, col = p.second;
                    if (row == 1) {
                        if (topCov[col] == 0) topZero.erase(col);
                        topCov[col] += 1;
                    } else {
                        if (bottomCov[col] == 0) bottomZero.erase(col);
                        bottomCov[col] += 1;
                    }
                }
            }

            // after expansion check if satisfied
            int firstZeroTop = topZero.empty() ? (n+1) : *topZero.begin();
            int lastZeroBottom = bottomZero.empty() ? 0 : *bottomZero.rbegin();
            int prefTop = firstZeroTop - 1;
            int suffBottom = lastZeroBottom + 1;
            if (prefTop >= suffBottom) {
                // all r' >= r up to V are valid
                ans += (long long)(V - r + 1);
            }

            // now remove value l from window (we are moving l -> l+1)
            // if current r < l then window is empty: set r = l
            if (r < l) {
                r = l;
            } else {
                // remove all occurrences of value l
                for (auto &p : occ[l]) {
                    int row = p.first, col = p.second;
                    if (row == 1) {
                        topCov[col] -= 1;
                        if (topCov[col] == 0) topZero.insert(col);
                    } else {
                        bottomCov[col] -= 1;
                        if (bottomCov[col] == 0) bottomZero.insert(col);
                    }
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
