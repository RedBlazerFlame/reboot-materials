#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main() {
    ll n, x;
    cin >> n >> x;

    vll a(n + 1, 0ll);
    for(ll i = 0; i < n; i++) {
        ll v;
        cin >> v;
        a[i + 1] = a[i] + v;
    }

    ll max_sum = 0ll;

    for(ll l = 0; l < n - x + 1ll; l++) {
        for(ll r = l + x - 1ll; r < n; r++) {
            max_sum = max(max_sum, (a[r + 1] - a[l]) / (r - l + 1ll));
        }
    }

    cout << max_sum << endl;
    return 0;
}