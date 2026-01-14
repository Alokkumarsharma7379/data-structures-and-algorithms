#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        long long pari =0;
        for(int i=n-1; i>=2; i--){
            for(int j=i;j<n;j=i+1){
                if(v[i] == v[j]){
                    i=j+1;
                    pari = pari + v[i];
                    v[i]=0;
                    v[i+1]=0;
                }
            }
        }
        sort(v.rbegin(),v.rend());
        
        pari = pari + v[0]+v[1];
        cout<<pari;
    }
}
// this is wrong i have to correct it