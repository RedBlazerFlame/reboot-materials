#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<bool> is_something(n + 1, false);
    is_something[0] = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j * i <= n; j++) is_something[j * i] = !is_something[j * i];
    }

    return 0;
}