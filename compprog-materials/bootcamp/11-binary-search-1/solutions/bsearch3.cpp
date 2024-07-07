#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n, 0);
    for(int& av : a) cin >> av;
    sort(a.begin(), a.end());
    while(q--) {
        int k; cin >> k;
        int l = -1, r = n;
        while(r - l > 1) {
            int m = (l + r) >> 1;
            if(a[m] <= k) l = m;
            else r = m;
        }
        cout << (0 <= l && l < n && a[l] == k ? "YES" : "NO") << endl;
    }
    return 0;
}