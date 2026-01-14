#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        long long sum = 0, mn = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            if (a[i] < mn) mn = a[i];
        }
        cout << (sum - mn) << '\n';
    }
    return 0;
}