#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> prev_costs(7, 0);
        for (int v = 1; v <= 6; v++)
        {
            prev_costs[v] = (a[0] == v ? 0 : 1);
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> curr_costs(7, 1e9);
            for (int v = 1; v <= 6; v++)
            { 
                int cost_to_set_v = (a[i] == v ? 0 : 1);

                for (int p = 1; p <= 6; p++)
                { 
                    if (p != v && p + v != 7)
                    {
                        curr_costs[v] = min(curr_costs[v], prev_costs[p] + cost_to_set_v);
                    }
                }
            }
            prev_costs = curr_costs; 
        }

        int ans = *min_element(prev_costs.begin() + 1, prev_costs.end());
        cout << ans << endl;
    }

    // int n; cin>>n;
    // vector<int> alok(n);
    // for(int i=0; i<n; i++){
    //     cin>>alok[i];
    // }
    // int count = 0;
    // for(int i=0; i<n; i++){
    //     if(((alok[i]+alok[i+1])==7) || ((alok[i]==alok[i+1]) && ((i+1)<n))) count++;
    // }
    // cout<<count<<endl;
}

