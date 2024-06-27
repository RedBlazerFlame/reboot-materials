/*
Solution for set 1
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vvll mll;

const ll MOD = 1'000'000'007ll;

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
    ll n;
    cin >> n;
    vll init = {1ll, 0ll, 0ll, 1ll};
    mll mat = {
        {0ll, 0ll, 0ll, 1ll},
        {0ll, 0ll, 1ll, 0ll},
        {0ll, 1ll, 0ll, 0ll},
        {1ll, 0ll, 0ll, 1ll}
    };
    

    cout << matvecmod(matpow(mat, n - 1, MOD), init, MOD)[3] << endl;

    return 0;
} 