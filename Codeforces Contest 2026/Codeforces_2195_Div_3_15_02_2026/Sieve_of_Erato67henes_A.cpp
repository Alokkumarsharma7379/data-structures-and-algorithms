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
        bool flag=false;
        sort(alok.begin(),alok.end());
        for(int i=0; i<n; i++){
            for(int i = 0; i < n; i++){
                if(alok[i] == 67) flag = true; // Bas 67 check karo
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}