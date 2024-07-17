#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<bool> vb;

const ll MOD = 1'000'000'007ll;

inline ll mu(const vb& sqfree, const vll& prime_facts, ll i) {
    return (sqfree[i] ? (prime_facts[i] & 0b1ll ? -1ll : 1ll) : 0ll);
}

ll fpw(ll b, ll pw, ll md) {
    if(pw == 0ll) return 1ll;

    ll sqr = fpw((b * b) % md, pw >> 1ll, md);

    return (pw & 0b1ll ? (sqr * b) % md : sqr);
}

ll inv(ll n, ll md) {
    return fpw(n, md - 2ll, md);
}

int main() {
    ll n;
    cin >> n;

    vb sqfree(n + 1, true);

    for(ll i = 2ll; i * i <= n; i++) {
        ll sqi = i * i;
        for(ll j = sqi; j <= n; j += sqi) {
            sqfree[j] = false;
        }
    }

    vll prime_facts(n + 1, 0);
    for(ll i = 2; i <= n; i++) {
        if(prime_facts[i] == 0) {
            for(ll j = i; j <= n; j += i) prime_facts[j]++;
        }
    }

    ll tot_num = 0ll;
    for(ll i = 1ll; i <= n; i++) {
        ll ndivi = n / i;
        tot_num += mu(sqfree, prime_facts, i) * ndivi * ndivi;
    }

    cout << ((tot_num % MOD) * inv((n * n) % MOD, MOD)) % MOD << endl;

    return 0ll;
}