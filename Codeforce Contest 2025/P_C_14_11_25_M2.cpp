#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<ll> a(n+1), pref(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            pref[i] = pref[i-1] + a[i];
        }

        ll base = pref[n];
        ll best_gain = 0;

        ll minB = LLONG_MAX;  // track minimum B[l]

        for(int r = 1; r <= n; r++){
            ll A = 1LL*r*r + r - pref[r];

            if(minB != LLONG_MAX)
                best_gain = max(best_gain, A - minB);

            ll B = 1LL*r*r - r - pref[r-1];
            minB = min(minB, B);
        }

        cout << base + best_gain << "\n";
    }
    return 0;
}