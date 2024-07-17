#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> phi(n + 1, 0ll);
    for(ll i = 0; i <= n; i++) {
        phi[i] = i;
    }
    phi[1] = 1;
    for(ll i = 2ll; i <= n; i++) {
        if(phi[i] == i) {
            for(ll j = 1ll; i * j <= n; j++) {
                phi[i * j] -= phi[i * j] / i;
            }
        }

        cout << phi[i] << " ";
    }
    cout << "\n";

    return 0;
}