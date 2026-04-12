// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t; cin>>t;
//     while(t--){
//         int n; cin>>n;
//         vector<int> permutation(n);
//         for(int i=0; i<n ; i++) cin>>permutation[i];
//         vector<int> alok(n);
//         for(int i=0; i<n ; i++) cin>>alok[i];
//         vector<int>compressed;
//         compressed.push_back(alok[0]);
//         for(int i=1; i<n; i++){
//             if(alok[i] != alok[i+1]){
//                 compressed.push_back(alok[i]);
//             }
//         }
//         int j=0;
//         bool ans = true;
//         for(int i=0; i<compressed.size();i++){
//             while(j<n && permutation[j] != compressed[i]){
//                 j++;
//             }
//             if(j == n){
//                 ans = false;
//                 break;
//             }
//             j++;
//         }
//         if(ans) cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//     }
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n), a(n);

        for (int i = 0; i < n; i++)
            cin >> p[i];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        
        vector<int> b;
        b.push_back(a[0]);

        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                b.push_back(a[i]);
            }
        }

        
        int j = 0; 
        bool ok = true;

        for (int i = 0; i < (int)b.size(); i++) {
            while (j < n && p[j] != b[i]) {
                j++;
            }

            if (j == n) {  
                ok = false;
                break;
            }

            j++; 
        }

        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
