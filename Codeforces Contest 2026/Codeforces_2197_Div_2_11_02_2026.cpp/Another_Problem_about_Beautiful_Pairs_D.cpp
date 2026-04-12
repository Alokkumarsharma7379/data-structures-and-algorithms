// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;

//         vector<long long> a(n + 1);
//         for (int i = 1; i <= n; i++)
//             cin >> a[i];

//         long long ans = 0;

//         for (int i = 1; i <= n; i++) {
//             for (long long j = i + a[i]; j <= n; j += a[i]) {
//                 if (a[i] * a[j] == j - i)
//                     ans++;
//             }
//         }

//         cout << ans << '\n';
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    // Square root bound (approx 632 for n=2e5)
    int B = sqrt(2 * n); 

    // Case 1: Pairs where a[i] is small (<= B)
    for (int v = 1; v <= B; v++) {
        for (int j = 1; j <= n; j++) {
            // formula: a[i] * a[j] = j - i 
            // Agar hum maan lein a[i] = v, toh i = j - v * a[j]
            ll i_target = (ll)j - (ll)v * a[j];
            
            if (i_target >= 1 && i_target < j && a[i_target] == v) {
                ans++;
            }
        }
    }

    // Case 2: Pairs where a[j] is small (<= B) AND a[i] is large (> B)
    // Yeh double counting avoid karne ke liye hai
    for (int v = 1; v <= B; v++) {
        for (int i = 1; i <= n; i++) {
            // Agar hum maan lein a[j] = v, toh j = i + a[i] * v
            ll j_target = (ll)i + (ll)a[i] * v;
            
            if (j_target <= n && j_target > i && a[j_target] == v && a[i] > B) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
