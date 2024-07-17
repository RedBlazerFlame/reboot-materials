#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num_div(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j * i <= n; j++) num_div[j * i]++;
        cout << num_div[i] << " ";
    }
    cout << "\n";

    return 0;
}