#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) {
        int x,y,z; cin >> x>>y>>z;
        int bx , by,bz;
        bool possible = true;
        for(int i=0;i<31;i++){
            bx = (x>>i)& 1;
            by = (y>>i)& 1;
            bz = (z>>i)& 1;
            if(!((bx == 0 && by == 0 && bz ==0)
                ||(bx == 0 && by == 0 && bz ==0)
                ||(bx == 0 && by == 1 && bz ==0)
                ||(bx == 0 && by == 0 && bz ==1)
                ||(bx == 1 && by == 0 && bz ==0)
                ||(bx == 1 && by == 1 && bz ==1))){
                    possible = false;
                    break;
                }
        }
        if(possible == true ){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    
    return 0;
}