/*
Solution for set 1
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vvll mll;

const ll MOD = 6'071'297ll;

mll idmat(ll n) {
    mll res;
    for(ll i = 0; i < n; i++) {
        vll res_row(n, 0ll);
        res_row[i] = 1ll;
        res.push_back(res_row);
    }
    return res;
}

mll matmatmod(const mll& m1, const mll& m2, ll md) {
    ll n = m1.size();
    mll res = idmat(n);

    ll cursum;

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cursum = 0ll;
            for(ll k = 0; k < n; k++) {
                cursum = (cursum + (m1[i][k] * m2[k][j])) % md;
            }

            res[i][j] = cursum;
        }
    }

    return res;
}

mll matpow(const mll& mat, ll pw, ll md) {
    if(pw == 0ll) return idmat(mat.size());
    mll new_base = matpow(matmatmod(mat, mat, md), pw >> 1, md);
    return (pw & 1 ? matmatmod(mat, new_base, md) : new_base);
}

ll fpw(ll base, ll pw, ll md) {
    if(pw == 0ll) return 1ll;
    ll nb = fpw((base * base) % md, pw >> 1ll, md);
    
    return (pw & 1 ? (base * nb) % md : nb);
}

ll pmod(ll n, ll md) {
    return ((n % md) + md) % md;
}

vll matvecmod(const mll& mat, const vll& vec, ll md) {
    ll n = mat.size();
    vll res(n, 0ll);

    ll cursum = 0ll;

    for(ll i = 0; i < n; i++) {
        cursum = 0ll;

        for(ll k = 0; k < n; k++) {
            cursum = (cursum + (mat[i][k] * vec[k])) % md;
        }

        res[i] = cursum;
    }

    return res;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    // ll n;
    // cin >> n;
    const ll n = 2951780976ll;
    vll init = {-1ll, 1ll};
    mll mat = {
        {0ll, 1ll},
        {1ll, 1ll}
    };
    
    // n = 2951780976
    
    vll fib_decomp = matvecmod(matpow(mat, n, MOD - 1ll), init, MOD - 1ll);

    cout << (fpw(1273ll, pmod(fib_decomp[0], MOD - 1ll), MOD) * fpw(1337ll, pmod(fib_decomp[1], MOD - 1ll), MOD)) % MOD << endl;

    return 0;
}