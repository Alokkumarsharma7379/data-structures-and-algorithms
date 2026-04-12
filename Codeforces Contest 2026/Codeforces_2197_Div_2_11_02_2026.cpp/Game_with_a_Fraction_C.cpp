#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        long long p,q; cin>>p>>q;
        long long d = q - p;
        if((d >= 1) && (d <= p/2)) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
}