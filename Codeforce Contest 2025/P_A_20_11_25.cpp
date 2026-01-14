#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n % 2 == 0){
            if(n%4 == 0){
                cout<<((n/4)+1)<<endl;
            }
            else{
                n= n-2;
                cout<<((n/4)+1)<<endl;
            }
        }
        else{
            cout<<0<<endl;
        }
    }
}