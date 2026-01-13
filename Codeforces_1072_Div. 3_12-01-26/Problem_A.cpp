#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        // int mini=INT_MAX;
        // for(int x=0; x<=n/2; x++){
        //     if((n-2*x)%3 == 0) mini = min(x,(n-2*x)/3);
        // }
        // cout<<mini<<endl;
        if(n<=3)  cout<<n<<endl;
        else{
            if(n%2 == 0) cout<<0<<endl;
            else cout<<1<<endl;
        }
    }
}