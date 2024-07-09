#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int l = 0, r = n + 1;
    while(r - l > 1) {
        int m = (l + r) >> 1;
        if(m * m <= n) l = m;
        else r = m;
    }
    cout << l << endl;
    return 0;
}