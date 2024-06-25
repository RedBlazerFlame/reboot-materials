#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

const ll MAX_SIZE = 201; // Update this as needed
vll memo(MAX_SIZE, -1ll);
ll fib(ll n) {
    if(n <= 1) return n;
    ll& ans = memo[n];
    if(ans == -1) {
        ans = fib(n - 1) + fib(n - 2);
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}