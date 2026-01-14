#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        int A = 0, B = 0;
        for (int i = 0; i < n; ++i) {
            A ^= a[i];
            B ^= b[i];
        }

        if (A == B) {
            cout << "Tie\n";
            continue;
        }

        int D = A ^ B;
        // get index of most significant bit (0-based)
        int p = 31 - __builtin_clz(D); // safe for D>0

        int last = -1;
        for (int i = n - 1; i >= 0; --i) {
            int delta = a[i] ^ b[i];
            if ((delta >> p) & 1) { last = i + 1; break; } // store 1-based index
        }

        // last should always be found because D has bit p set so some delta has it
        if (last == -1) {
            cout << "Tie\n"; // safe fallback (shouldn't happen)
        } else if (last % 2 == 1) {
            cout << "Ajisai\n";
        } else {
            cout << "Mai\n";
        }
    }

    return 0;
}
