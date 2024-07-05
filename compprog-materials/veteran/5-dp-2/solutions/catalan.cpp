#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> catalan;
    catalan.push_back(1);
    for(int n = 1; n <= N; n++) {
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += catalan[i] * catalan[n - i - 1];
        }
        catalan.push_back(ans);
    }
    cout << catalan[N] << endl;
    return 0;
}