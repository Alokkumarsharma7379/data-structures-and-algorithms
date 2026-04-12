#include<bits/stdc++.h>
using namespace std;
int alok(int i) {
    // Jab tak index even hai, root ki taraf jao (i/2)
    while (i > 0 && i % 2 == 0) {
        i /= 2;
    }
    return i;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin >> n;
    vector<int> a(n + 1);
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
        for (int i = 1; i <= n; i++) {
        // Kya element a[i] apne current index i se 
        // apni sahi position (jo ki a[i] khud hai) tak ja sakta hai?
        if (alok(i) != alok(a[i])) {
            flag = false;
            break;
        }
    }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}