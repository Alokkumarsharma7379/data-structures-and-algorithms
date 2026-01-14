#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        unordered_set<int> s;
        for (int x : a) if (x > 0) s.insert(x); // only positive values

        cout <<(int)s.size()<< '\n';

    }
    return 0;
}
