#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int ans=0;
        vector<int>alok(n);
        for(int i=0; i<n; i++) cin>>alok[i];
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                ans = max(ans, alok[i]^alok[j]);
            }
        }
        cout<<ans<<endl;
    }
}