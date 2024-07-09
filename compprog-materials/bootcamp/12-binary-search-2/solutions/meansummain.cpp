/*
a - k'

find some subarray whose subarray sum is positive
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

bool poss(const vll& a, ll n, ll x, ll k) {
    vll b(n + 1, 0ll);
    for(ll i = 0; i <= n; i++) {
        b[i] = a[i] - i * k;
    }

    vll bsufmax(n + 1, 0ll);
    bsufmax[n] = numeric_limits<ll>::min();

    for(ll i = n - 1; i >= 0; i--) {
        bsufmax[i] = max(bsufmax[i + 1], b[i + 1]);
    }

    // bsufmax[i] stores the maximum of b[i + 1], b[i + 2], ...

    for(ll i = 0; i + x - 1ll < n; i++) {
        if(b[i] <= bsufmax[i + x - 1ll]) return true;
    }
    return false;
}

int main() {
    ll n, x;
    cin >> n >> x;

    vll a(n + 1, 0ll);
    for(ll i = 0; i < n; i++) {
        ll v;
        cin >> v;
        a[i + 1] = a[i] + v;
    }

    // NOTE: the maximum possible value for the mean is 10^9,
    // since the maximum possible for any single element is 10^9
    ll l = 0, r = 1'000'000'000ll;

    while(r - l > 1) {ll m = (l + r) >> 1ll; (poss(a, n, x, m) ? l : r) = m;}

    cout << l << endl;

    return 0;
}