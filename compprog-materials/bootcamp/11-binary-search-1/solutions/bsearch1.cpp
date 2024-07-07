#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string query(int n) {
    cout << "QUERY " << n << "\n";
    string ans;
    cin >> ans;
    return ans;
}

int main() {
    int maxn;
    cin >> maxn;
    int l = 1, r = maxn;
    int ans;
    while(r - l > 0) {
        int m = (l + r) >> 1;
        string qans = query(m);
        if(qans == "CORRECT") {
            ans = m;
            break;
        } else if(qans == "LOWER") {
            r = m - 1;
        } else if(qans == "HIGHER") {
            l = m + 1;
        }
    }
    if(l == r) ans = l;
    cout << "ANS " << ans << endl;

    return 0;
}