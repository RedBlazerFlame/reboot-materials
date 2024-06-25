#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
    int n, nc;
    cin >> n >> nc;
    vi denoms(nc + 1, 1);
    for(int i = 1; i <= nc; i++) {
        cin >> denoms[i];
    }
    vi ans(n + 1, numeric_limits<int>::max());
    ans[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int c : denoms) if(i - c >= 0) ans[i] = min(ans[i], ans[i - c] + 1);
    }
    cout << ans[n] << endl;
}