#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int MAX_MEMO = 200'001;
// numeric_limits<int>::max() returns the largest possible integer
// and acts as "positive infinity"
vi memo(MAX_MEMO, numeric_limits<int>::max());
int min_change(const vi& c, int n) {
    if(n == 0) return 0;
    int& ans = memo[n];
    if(ans == numeric_limits<int>::max()) {
        for(int cur_denom : c) {
            // Skip the current denomination if it doesn't fit
            if(n - cur_denom < 0) continue;
            ans = min(ans, min_change(c, n - cur_denom) + 1);
        }
    }
    return ans;
}

int main() {
    int n, nc;
    cin >> n >> nc;

    vi currencies(nc + 1, 1);
    for(int i = 1; i <= nc; i++) {
        cin >> currencies[i];
    }

    cout << min_change(currencies, n) << endl;
}