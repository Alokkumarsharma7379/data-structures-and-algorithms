#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
    while(t--) {

        int n;
        cin >> n;
        vector<long long> a(n);

        long long base_sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            base_sum += a[i];
        }

        long long max_gain = 0;

        for(int l = 0; l < n; l++) {
            long long sum = 0;
            for(int r = l; r < n; r++) {
                sum += a[r];

                long long len = r - l + 1;
                long long value = (l + 1) + (r + 1); // corrected
                long long gain = len * value - sum;

                max_gain = max(max_gain, gain);
            }
        }

        cout << base_sum + max_gain << "\n";
    }
}
