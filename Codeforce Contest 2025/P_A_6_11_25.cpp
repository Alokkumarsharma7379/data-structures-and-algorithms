#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int x; cin>>x;
        sort(v.begin(),v.end());
        
        if(x >= v[0] && x <= v[n-1]){
            cout<<"YES";
            cout<<endl;
        }
        else{
            cout<<"NO";
            cout<<endl;
        }
    }
}
