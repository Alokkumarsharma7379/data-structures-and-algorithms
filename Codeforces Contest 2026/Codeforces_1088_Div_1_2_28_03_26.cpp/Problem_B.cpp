#include <bits/stdc++.h>
using namespace std;
static long long divisor_count(long long n) {
    long long cnt = 0;
    for (long long d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            cnt += 1;
            if (d * d != n) cnt += 1;
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        long long x, y; cin >> x >> y;
        long long s = x - y;
        long long ans;
        if (s == 0) ans = 1;
        else ans = divisor_count(llabs(s));
        cout<<ans<<endl;
        bool first = true;
        auto print_val = [&](int v) {
            if (!first) cout << ' ';
            first = false;
            cout << v;
        };
        if (s >= 0) {
            for (long long i = 0; i < x; ++i) print_val(1);
            for (long long i = 0; i < y; ++i) print_val(-1);
        } 
        else {
            for (long long i = 0; i < y; ++i) print_val(-1);
            for (long long i = 0; i < x; ++i) print_val(1);
        }
        cout<<endl;
    }
    return 0;
}