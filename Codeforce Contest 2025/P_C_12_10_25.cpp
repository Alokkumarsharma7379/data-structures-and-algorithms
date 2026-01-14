#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        unsigned int n;
        cin >> n;
        bool ok = false;

        // n < 2^30 per problem, so L up to 30 is enough; using 31 for safety
        for (int L = 1; L <= 31 && !ok; ++L) {
            // n must fit in L bits (otherwise bits >= L are nonzero and cannot be produced)
            if (n >= (1u << L)) continue;

            bool impossible = false;
            // Build adjacency list of constraints: for i != j, b[i] xor b[j] = ni
            vector<vector<pair<int,int>>> adj(L);
            for (int i = 0; i < L; ++i) {
                int j = L - 1 - i;
                int ni = (int)((n >> i) & 1u);
                if (i == j) {
                    // middle bit constraint when L is odd: b[i] xor b[i] = 0 must equal ni
                    if (ni != 0) { impossible = true; break; }
                } else {
                    // add constraint once (both directions)
                    adj[i].push_back({j, ni});
                    // adj[j].push_back({i, ni}); // we'll add when i iterates or add both now:
                    // but to be safe, add both (we added i->j already; ensure j->i also present)
                    // We'll allow adding duplicates; it's fine.
                }
            }
            if (impossible) continue;
            // Ensure symmetric adjacency (we only added one direction above for each pair when i<->j both added since loop covers all i)
            // But to be safe, let's rebuild properly:
            vector<vector<pair<int,int>>> g(L);
            for (int i = 0; i < L; ++i) {
                int j = L - 1 - i;
                if (i == j) continue;
                int ni = (int)((n >> i) & 1u);
                g[i].push_back({j, ni});
                g[j].push_back({i, ni});
            }

            // Values: -1 unknown, 0 or 1 assigned
            vector<int> val(L, -1);
            // Highest bit must be 1 so x has length L
            val[L-1] = 1;

            bool contradiction = false;
            // Propagate each connected component. If a node unassigned, seed it with 0 (except highest bit already set).
            for (int s = 0; s < L && !contradiction; ++s) {
                if (val[s] == -1) {
                    // seed arbitrary 0
                    val[s] = 0;
                }
                // BFS
                queue<int> q;
                q.push(s);
                while (!q.empty() && !contradiction) {
                    int u = q.front(); q.pop();
                    for (auto &pr : g[u]) {
                        int v = pr.first;
                        int w = pr.second; // val[u] xor val[v] must equal w
                        if (val[v] == -1) {
                            val[v] = val[u] ^ w;
                            q.push(v);
                        } else {
                            if ((val[u] ^ val[v]) != w) {
                                contradiction = true;
                                break;
                            }
                        }
                    }
                }
            }
            if (contradiction) continue;
            // Ensure highest bit remained 1
            if (val[L-1] != 1) continue;

            // Build x and f(x) and verify
            unsigned int x = 0, fx = 0;
            for (int i = 0; i < L; ++i) {
                if (val[i] == 1) {
                    x |= (1u << i);
                    fx |= (1u << (L - 1 - i));
                }
            }
            if (x == 0) continue; // x must be positive
            if ((x ^ fx) == n) {
                ok = true;
                break;
            }
            // else try next L
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}