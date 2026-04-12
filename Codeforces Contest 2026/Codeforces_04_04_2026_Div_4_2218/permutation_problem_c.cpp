#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>alok;
        // for(int i=1; i<=n; i++){
        //     alok[i*3]=i;
        //     alok[i]=(i+4);
        //     alok[i*3+2]=(i+5);
        // }
        // for(int i=1; i<3*n;i++){
        //     if(i%3==0) continue;
        //     else alok[i]=n+i
        // }
        for(int i=1; i<=n; i++){
            alok.push_back(i);
            alok.push_back(n+2*i-1);
            alok.push_back(n+2*i);
        }
        for(int i=0; i<3*n-1;i++){
            cout<<alok[i]<<" ";
        }
        cout<<alok[3*n-1]<<endl;

    }
}