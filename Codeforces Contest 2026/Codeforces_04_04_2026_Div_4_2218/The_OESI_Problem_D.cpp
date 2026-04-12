#include<bits/stdc++.h>
using namespace std;
// int main(){
//     int t; cin>>t;
//     while(t--){
//         long long alk=1;
//         long long n; cin>>n;
//         vector<long long>alok(n);
//         for(int i=0; i<n; i++){
//             alok[i]= alk;
//             alk*=2;
//         }
//         for(long long i=0; i<n-1; i++) cout<<alok[i]<<" ";
//         cout<<alok[n-1]<<endl;
//     }
// }
int main(){
    vector<long long>prime;
    int hi = 200000;
    vector<bool> isitprime(hi+1,true);
    isitprime[0]=false;
    isitprime[1]=false;
    for(int i=2;i*i<=hi;i++){
        if(isitprime[i]){
            for(int j=i*i;j<=hi;j+=i){
                isitprime[j]=false;
            }
        }
    }
    for(int i=2; i<=hi;i++){
        if(isitprime[i]==true){
            prime.push_back(i);
        }
    }
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long>alok(n);
        for(int i=0; i<n-1; i++){
            alok[i]=prime[i]*prime[i+1];
        }
        alok[n-1]=prime[n-1]*prime[0];
        for(int i=0; i<n-1; i++){
            cout<<alok[i]<<" ";
        }
        cout<<alok[n-1]<<endl;
    }
}