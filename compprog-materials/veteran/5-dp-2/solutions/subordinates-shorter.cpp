#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll solve(const vvll& adj, vll& subordinates, ll i) {
    return subordinates[i] = accumulate(adj[i].begin(), adj[i].end(), 0ll, [&adj, &subordinates](ll acc, ll cur) {return acc + 1ll + solve(adj, subordinates, cur);});
}

int main() {
    ll n;
    cin >> n;

    // Creating an Adjacency List
    vvll adj;
    for(ll i = 0; i < n; i++) {
        vll adjr;
        adj.push_back(adjr);
    }

    for(ll i = 1; i < n; i++) {
        ll par;
        cin >> par;
        par--;

        adj[par].push_back(i);
    }

    // Creating an array to store the answers
    vll subordinates(n, -1ll);

    solve(adj, subordinates, 0ll);

    // Printing the Answer
    for(ll i = 0; i < n; i++) {
        cout << subordinates[i] << " ";
    }
    cout << endl;

    return 0;
}