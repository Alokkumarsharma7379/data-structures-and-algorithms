#include<bits/stdc++.h>
using namespace std;
int digitsum(int n){
    int sum = 0;
    while(n>0){
        sum += n%10;
        n = n/10;
    }
    return sum;
}
int main(){
    int t; cin>>t;
    while(t--){
        long long x; cin>>x;
            // if(x%9 == 0){
            //     cout<<10<<endl;
            // }
            // else{
            //     cout<<0<<endl;
            // }
            int count =0;
        for(long i = x; i<(x+200); i++){
            if((i-digitsum(i))==x){
                count++;
            }
        }
        cout<<count<<endl;
    }
}