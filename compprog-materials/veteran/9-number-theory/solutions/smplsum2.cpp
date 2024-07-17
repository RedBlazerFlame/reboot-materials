#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
	// your code goes here
    ll MAX_PHI = 10000ll;
    vector<ll> phi(MAX_PHI + 1, 0);
    for(ll i = 0; i <= MAX_PHI; i++) {
        phi[i] = i;
    }
    for(ll i = 2; i <= MAX_PHI; i++) {
        if(phi[i] == i) {
            for(ll j = i; j <= MAX_PHI; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    for(ll i = 0; i <= MAX_PHI; i++) {
        phi[i] *= i;
    }

    vector<ll> ans(MAX_PHI + 1, 0ll);
    for(ll i = 1; i <= MAX_PHI; i++) {
        for(ll j = i; j <= MAX_PHI; j+=i) {
            ans[j] += phi[i];
        }
    }
    
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        cout << ans[n] << "\n";
    }
    cout << flush;
    
    return 0;
}
