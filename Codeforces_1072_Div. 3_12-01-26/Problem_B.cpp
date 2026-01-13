#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int s,k,m; 
        cin>>s>>k>>m;
        if(s<=k){
            if(m%k>s) cout<<0<<endl;
            else cout<<s-(m%k)<<endl; // m%k<s
        }
        else{ // s>k
            //cout<<(k-(m%k))<<endl;
            if((m/k)%2 == 0) cout<<s-(m%k)<<endl;
            else cout<<k-(m%k)<<endl;
        } 
    }
}