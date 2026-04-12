#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        vector<int>alok(7);
        for(int i=0; i<7; i++){
            cin>>alok[i];
        }
        sort(alok.begin(),alok.end());
        int sum=0;
        for(int i=0; i<6; i++){
            sum=sum+(-1*alok[i]);
        }
        sum+=alok[6];
        cout<<sum<<endl;
    }
}