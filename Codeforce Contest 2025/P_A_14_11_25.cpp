#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a; cin>>a;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int s=0;
        int e = (n-1);
        int mid = s + (e-s)/2;
        int b=0;
        if(a>v[mid]) b = a-1;
        if(a<v[mid]) b = a+1;
        if(a == v[mid]) b=a+1;

        cout<<b<<endl;
    }
}