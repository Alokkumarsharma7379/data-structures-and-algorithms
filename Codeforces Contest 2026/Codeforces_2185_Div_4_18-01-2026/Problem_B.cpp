#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> alok(n);
        for(int i=0; i<n; i++){
            cin>>alok[i];
        }
        sort(alok.begin(),alok.end());
        int ans = n*(alok[n-1]);
        cout<<ans<<endl;
    }
}