#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> prime_facts(n + 1, 0);
    for(int i = 2; i <= n; i++) {
        if(prime_facts[i] == 0) {
            for(int j = 1; j * i <= n; j++) prime_facts[j * i]++;
        }
        cout << prime_facts[i] << " ";
    }
    cout << "\n";

    return 0;
}