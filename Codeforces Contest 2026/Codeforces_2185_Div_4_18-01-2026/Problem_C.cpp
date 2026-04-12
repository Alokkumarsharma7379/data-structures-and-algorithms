#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort and remove duplicates
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    
    int max_mex = 0;
    int current_streak = 0;
    
    for (int i = 0; i < a.size(); i++) {
        if (i > 0 && a[i] == a[i-1] + 1) {
            current_streak++;
        } else {
            current_streak = 1;
        }
        max_mex = max(max_mex, current_streak);
    }
    
    // If the array is empty, MEX is 0; otherwise, it's the streak length
    if (n == 0) cout << 0 << endl;
    else cout << max_mex << endl;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
