#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

unordered_map<ll,int> dp;
ll K;

int solveRec(ll x) {
    if (x == K) return 0;
    if (x < K) return INF;
    auto it = dp.find(x);
    if (it != dp.end()) return it->second;
    ll a = x / 2;
    ll b = x - a; // ceil(x/2)
    int res = 1 + min(solveRec(a), solveRec(b));
    dp[x] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        ll n;
        cin >> n >> K;
        dp.clear();
        if (K > n) {
            cout << -1 << '\n';
            continue;
        }
        int ans = solveRec(n);
        if (ans >= INF) cout << -1 << '\n';
        else cout << ans << '\n';
    }
    return 0;
}
