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
    int l = 0, r = maxn + 1;
    while(r - l > 1) {
        int m = (l + r) >> 1;
        if(query(m) == "LOWER") r = m;
        else l = m;
    }
    cout << "ANS " << l << endl;
    return 0;
}