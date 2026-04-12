#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

static const ll MOD = 1000000007LL;
static const int BIT = 29;
static const ll BASE = 1LL << 15;

vector<ll> fact, invfact;

ll modpow(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

void fft(vector<complex<ld>> &a, bool invert) {
    int n = (int)a.size();

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        ld ang = 2.0L * acosl(-1.0L) / len * (invert ? -1 : 1);
        complex<ld> wlen(cosl(ang), sinl(ang));
        for (int i = 0; i < n; i += len) {
            complex<ld> w(1);
            for (int j = 0; j < len / 2; ++j) {
                complex<ld> u = a[i + j];
                complex<ld> v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (auto &x : a) x /= n;
    }
}

vector<ll> convolution_int(const vector<ll> &a, const vector<ll> &b) {
    int n1 = (int)a.size();
    int n2 = (int)b.size();
    int n = 1;
    while (n < n1 + n2 - 1) n <<= 1;

    vector<complex<ld>> fa(n), fb(n);
    for (int i = 0; i < n1; ++i) fa[i] = (ld)a[i];
    for (int i = 0; i < n2; ++i) fb[i] = (ld)b[i];

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; ++i) fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> res(n1 + n2 - 1);
    for (int i = 0; i < (int)res.size(); ++i) {
        res[i] = (ll)llround(fa[i].real());
    }
    return res;
}

vector<ll> convolution_mod(const vector<ll> &a, const vector<ll> &b) {
    int n1 = (int)a.size();
    int n2 = (int)b.size();

    vector<ll> a0(n1), a1(n1), a01(n1);
    vector<ll> b0(n2), b1(n2), b01(n2);

    for (int i = 0; i < n1; ++i) {
        a0[i] = a[i] & (BASE - 1);
        a1[i] = a[i] >> 15;
        a01[i] = a0[i] + a1[i];
    }
    for (int i = 0; i < n2; ++i) {
        b0[i] = b[i] & (BASE - 1);
        b1[i] = b[i] >> 15;
        b01[i] = b0[i] + b1[i];
    }

    vector<ll> c00 = convolution_int(a0, b0);
    vector<ll> c11 = convolution_int(a1, b1);
    vector<ll> c01 = convolution_int(a01, b01);

    int sz = n1 + n2 - 1;
    vector<ll> res(sz);

    for (int i = 0; i < sz; ++i) {
        ll cross = c01[i] - c00[i] - c11[i];

        ll val = 0;
        val = (val + (c00[i] % MOD)) % MOD;
        ll crossMod = (cross % MOD + MOD) % MOD;
        val = (val + crossMod * (BASE % MOD)) % MOD;
        val = (val + (c11[i] % MOD) * (BASE % MOD) % MOD * (BASE % MOD) % MOD) % MOD;

        res[i] = val;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int MAXN = 100000 + 5;
    fact.resize(MAXN);
    invfact.resize(MAXN);

    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) fact[i] = fact[i - 1] * i % MOD;
    invfact[MAXN - 1] = modpow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 1; i > 0; --i) invfact[i - 1] = invfact[i] * i % MOD;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<ll> alok(n + 1);
        alok[0] = (1LL << BIT) - 1;   // b0 = 2^29 - 1
        for (int i = 1; i <= n; ++i) cin >> alok[i];

        vector<ll> sharma(n + 1), kumar(n + 1);

        for (int i = 0; i <= n; ++i) {
            sharma[i] = alok[i] * fact[i] % MOD;
            if (i % 2 == 0) kumar[i] = invfact[i];
            else kumar[i] = (MOD - invfact[i]) % MOD;
        }

        vector<ll> alok_rev(n + 1);
        for (int i = 0; i <= n; ++i) {
            alok_rev[i] = sharma[n - i];
        }

        vector<ll> con = convolution_mod(alok_rev, kumar);

        vector<int> cnt(BIT, 0);

        for (int d = 0; d <= n; ++d) {
            ll coef = con[n - d] * invfact[d] % MOD;

            for (int bit = 0; bit < BIT; ++bit) {
                if (coef & (1LL << bit)) {
                    cnt[bit] = d;
                }
            }
        }

        vector<int> ans(n, 0);
        for (int bit = 0; bit < BIT; ++bit) {
            for (int i = 0; i < cnt[bit]; ++i) {
                ans[i] |= (1 << bit);
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << ans[i] << (i + 1 == n ? '\n' : ' ');
        }
    }

    return 0;
}