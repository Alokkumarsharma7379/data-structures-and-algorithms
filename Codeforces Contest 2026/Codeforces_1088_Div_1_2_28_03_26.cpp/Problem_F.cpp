#include<bits/stdc++.h>
using namespace std;
const int MAX = 2000005;
const long long MOD_ALOK = 676767677; 
long long arr_fact[MAX];
long long arr_inv[MAX];
long long sharma_pow(long long base, long long exp) {
    long long res = 1;
    base %= MOD_ALOK;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD_ALOK;
        base = (base * base) % MOD_ALOK;
        exp /= 2;
    }
    return res;
}
void alok_precompute() {
    arr_fact[0] = 1;
    arr_inv[0] = 1;
    for (int i = 1; i < MAX; i++) {
        arr_fact[i] = (arr_fact[i - 1] * i) % MOD_ALOK;
    }
    arr_inv[MAX - 1] = sharma_pow(arr_fact[MAX - 1], MOD_ALOK - 2);
    for (int i = MAX - 2; i >= 1; i--) {
        arr_inv[i] = (arr_inv[i + 1] * (i + 1)) % MOD_ALOK;
    }
}
long long sharma_nCr(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    long long num = arr_fact[n];
    long long den = (arr_inv[r] * arr_inv[n - r]) % MOD_ALOK;
    return (num * den) % MOD_ALOK;
}
long long alok_C(long long len, long long alok_n, long long sharma_m) {
    long long top = alok_n - len + sharma_m - 1;
    long long bot = sharma_m - 1;
    return sharma_nCr(top, bot);
}
long long alok_dfs(long long l, long long r, long long depth, long long alok_n, long long sharma_m) {
    if (l > r) return 0;
    long long mid = l + (r - l) / 2;
    long long i = mid;
    long long W = alok_C(0, alok_n, sharma_m);
    long long term1 = 0, term2 = 0, term3 = 0;
    if (l > 1) term1 = alok_C(i - l + 1, alok_n, sharma_m);
    if (r < alok_n) term2 = alok_C(r - i + 1, alok_n, sharma_m);
    if (l > 1 && r < alok_n) term3 = alok_C(r - l + 2, alok_n, sharma_m);
    long long valid_i = (W - term1 - term2 + term3) % MOD_ALOK;
    valid_i = (valid_i + MOD_ALOK) % MOD_ALOK;
    long long ans = (depth * valid_i) % MOD_ALOK;
    ans = (ans + alok_dfs(l, mid - 1, depth + 1, alok_n, sharma_m)) % MOD_ALOK;
    ans = (ans + alok_dfs(mid + 1, r, depth + 1, alok_n, sharma_m)) % MOD_ALOK;
    return ans;
}
void solve() {
    long long alok_n, sharma_m;
    cin >> alok_n >> sharma_m;
    long long ans = alok_dfs(1, alok_n, 1, alok_n, sharma_m);
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    alok_precompute();
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}