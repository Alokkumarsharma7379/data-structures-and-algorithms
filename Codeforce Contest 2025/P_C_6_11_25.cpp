#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        vector<long long> b(m), c(m);
        for (auto &x : b) cin >> x;
        for (auto &x : c) cin >> x;

        multiset<long long> swords(a.begin(), a.end());
        vector<pair<long long, long long>> monsters(m);
        for (int i = 0; i < m; ++i)
            monsters[i] = {b[i], c[i]};

        // ✅ Sort profitable monsters first, then by life
        sort(monsters.begin(), monsters.end(), [](auto &p1, auto &p2) {
            if ((p1.second > 0) != (p2.second > 0))
                return p1.second > 0;
            return p1.first < p2.first;
        });

        long long kills = 0;

        for (auto &monster : monsters) {
            long long life = monster.first;
            long long reward = monster.second;

            auto it = swords.lower_bound(life);
            if (it == swords.end()) continue;

            long long x = *it;
            swords.erase(it);
            kills++;

            if (reward > 0)
                swords.insert(max(x, reward));
        }

        cout << kills << "\n";
    }
    return 0;
}
