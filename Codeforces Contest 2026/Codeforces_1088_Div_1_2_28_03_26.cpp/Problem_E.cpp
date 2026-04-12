#include<bits/stdc++.h>
using namespace std;
const int MAX_PRIME = 1000005;
int min_prime[MAX_PRIME];
vector<int> sieve_primes;
void sharma_sieve() {
    for (int i = 2; i < MAX_PRIME; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
            sieve_primes.push_back(i);
        }
        for (int p : sieve_primes) {
            if (p > min_prime[i] || (long long)i * p >= MAX_PRIME) break;
            min_prime[i * p] = p;
        }
    }
}
vector<long long> get_kumar_primes(long long n) {
    vector<long long> factors;
    for (int p : sieve_primes) {
        if ((long long)p * p > n) break;
        if (n % p == 0) {
            factors.push_back(p);
            while (n % p == 0) n /= p;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}
long long sharma_val[200005];
vector<int> sharma_adj[200005];
long long alok_ans[200005];
vector<long long> kumar_available_primes[200005];
void solve() {
    int n;
    if (!(cin >> n)) return;

    for (int i = 1; i <= n; ++i) {
        sharma_adj[i].clear();
        kumar_available_primes[i].clear();
    }

    for (int i = 0; i < n; ++i) {
        int u = n - i;
        int k;
        cin >> sharma_val[u] >> k;
        for (int j = 0; j < k; ++j) {
            int child; cin >> child;
            sharma_adj[u].push_back(child);
        }

        long long current_f = 1;
        for (int v : sharma_adj[u]) {
            current_f += alok_ans[v];
        }

        vector<long long> u_primes = get_kumar_primes(sharma_val[u]);
        long long merged_p = -1;
        for (int v : sharma_adj[u]) {
            for (long long p : kumar_available_primes[v]) {
                if (sharma_val[u] % p == 0) {
                    merged_p = p; // Found a prime that works
                    goto found;
                }
            }
        }
        found:
        if (merged_p != -1) {
            current_f--;
            for (int v : sharma_adj[u]) {
                for (long long p : kumar_available_primes[v]) {
                    if (sharma_val[u] % p == 0) {
                        kumar_available_primes[u].push_back(p);
                    }
                }
            }
            sort(kumar_available_primes[u].begin(), kumar_available_primes[u].end());
            kumar_available_primes[u].erase(unique(kumar_available_primes[u].begin(), kumar_available_primes[u].end()), kumar_available_primes[u].end());
        } else {
            kumar_available_primes[u] = u_primes;
        }

        alok_ans[u] = current_f;
        cout << alok_ans[u] << "\n";
        cout.flush();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sharma_sieve();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}