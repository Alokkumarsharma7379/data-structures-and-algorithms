// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// int main()
// {
//     // Fast I/O
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n; cin >> n;
//         vector<ll> f(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> f[i];
//         }
//         // Agar n = 2 hai toh simple linear equations banti hain
//         // f(1) = a1*|1-1| + a2*|2-1| = a2
//         // f(2) = a1*|2-2| + a2*|1-2| = a1
//         if (n == 2)
//         {
//             cout << f[2] << " " << f[1] << endl;
//             break;
//         }
//         vector<ll> a(n + 1);
//         // Step 1: Intermediate elements calculate karein (2 to n-1)
//         // Formula: 2*a[i] = f(i-1) + f(i+1) - 2*f(i)
//         for (int i = 2; i < n; i++)
//         {
//             a[i] = (f[i - 1] + f[i + 1] - 2 * f[i]) / 2;
//         }

//         // Step 2: Boundary elements a[1] aur a[n] ke liye solve karein
//         // Hum jante hain: f(2) - f(1) = a1 - (a2 + a3 + ... + an)
//         // Aur: f(n) - f(n-1) = (a1 + a2 + ... + an-1) - an

//         // Let S = a1 + a2 + ... + an
//         // f(2) - f(1) = 2*a1 - S
//         // f(n) - f(n-1) = S - 2*an

//         // In dono ko use karke a1 aur an nikalne ke liye hum intermediate sum chahiye
//         ll intermediate_sum = 0;
//         for (int i = 2; i < n; i++)
//             intermediate_sum += a[i];

//         // f(1) = sum_{i=2 to n} a[i] * (i-1)
//         // f(1) = a[2]*1 + a[3]*2 + ... + a[n-1]*(n-2) + a[n]*(n-1)
//         ll current_f1_contribution = 0;
//         for (int i = 2; i < n; i++)
//         {
//             current_f1_contribution += a[i] * (i - 1);
//         }

//         // a[n] ki value f(1) se direct nikal sakti hai:
//         a[n] = (f[1] - current_f1_contribution) / (n - 1);

//         // Ab S nikalna asaan hai f(n) se:
//         // f(n) = a[1]*(n-1) + a[2]*(n-2) + ... + a[n-1]*1
//         ll current_fn_contribution = 0;
//         for (int i = 2; i < n; i++)
//         {
//             current_fn_contribution += a[i] * (n - i);
//         }

//         a[1] = (f[n] - current_fn_contribution) / (n - 1);

//         // Final Output
//         for (int i = 1; i <= n; i++)
//         {
//             cout << a[i] << (i == n ? "" : " ");
//         }
//         cout << endl;
//     }
// }
// // upar wala break statement ki wajah se test case 2 me alat aa rha 
// // h hme break nhi countinue use karke next text case par jaana hoga...
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<ll> f(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> f[i];
        }

        if (n == 2) {
            cout << f[2] << " " << f[1] << "\n";
            continue;
        }

        vector<ll> a(n + 1);
        

        for (int i = 2; i < n; i++) {
            a[i] = (f[i - 1] + f[i + 1] - 2 * f[i]) / 2;
        }

        ll current_f1_contribution = 0;
        for (int i = 2; i < n; i++) {
            current_f1_contribution += a[i] * (i - 1);
        }
        a[n] = (f[1] - current_f1_contribution) / (n - 1);

        ll current_fn_contribution = 0;
        for (int i = 2; i < n; i++) {
            current_fn_contribution += a[i] * (n - i);
        }
        a[1] = (f[n] - current_fn_contribution) / (n - 1);


        for (int i = 1; i <= n; i++) {
            cout << a[i] << (i == n ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
