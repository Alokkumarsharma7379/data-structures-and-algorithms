#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        bool flag = 1;
        int n; cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        for(int i=1;i<(n-1);i=i+2){
            if(a[i]!=a[i+1]){
                flag = 0;
            }
        }
        if(flag == 1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}