// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t; 
//     cin >> t;

//     while(t--){
//         int n, m;
//         long long h;
//         cin >> n >> m >> h;

//         vector<long long> original(n), a(n);
//         for(int i = 0; i < n; i++){
//             cin >> original[i];
//             a[i] = original[i];
//         }

//         for(int i = 0; i < m; i++){
//             int b;
//             long long c;
//             cin >> b >> c;
//             b--;

//             a[b] += c;

//             if(a[b] > h){
//                 // crash → reset whole array
//                 a = original;
//             }
//         }

//         for(long long x : a) cout << x << " ";
//         cout << "\n";
//     }
// }
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        long long h;
        cin >> n >> m >> h;

        vector<long long> original(n);
        for(int i = 0; i < n; i++) cin >> original[i];

        vector<long long> add(n, 0);
        vector<int> last_used(n, -1);

        int current_version = 0;

        for(int i = 0; i < m; i++){
            int b;
            long long c;
            cin >> b >> c;
            b--;

            // if index not used after last crash
            if(last_used[b] != current_version){
                add[b] = 0;
                last_used[b] = current_version;
            }

            add[b] += c;

            if(original[b] + add[b] > h){
                // crash
                current_version++;
            }
        }

        for(int i = 0; i < n; i++){
            if(last_used[i] == current_version)
                cout << original[i] + add[i] << " ";
            else
                cout << original[i] << " ";
        }
        cout << "\n";
    }
}
