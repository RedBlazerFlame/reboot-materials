#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class BST {
    public:
        BST* lt, *rt;
        ll v;

        BST(ll a_v): v(a_v), lt(nullptr), rt(nullptr) {};

        BST* insert(ll nv) {
            BST*& insert_dir = (nv <= v ? lt : rt);
            if(insert_dir == nullptr) {
                insert_dir = new BST(nv);
                return insert_dir;
            } else {
                return insert_dir->insert(nv);
            }
        }

        BST* find(ll qv) {
            if(v == qv) return this;

            if((qv < v && lt == nullptr) || (qv > v && rt == nullptr)) return nullptr;
            return (qv < v ? lt : rt)->find(qv);
        }

        ll lower_bound(ll qv) {
            return _lower_bound(qv, numeric_limits<ll>::max());
        }

        ll _lower_bound(ll qv, ll cur_min) {
            if(v == qv) return v;

            if(v >= qv) cur_min = min(cur_min, v);

            if((qv < v && lt == nullptr) || (qv > v && rt == nullptr)) return cur_min;

            return (qv < v ? lt : rt)->_lower_bound(qv, cur_min);
        }
};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    ll q;
    cin >> q;

    BST tree(numeric_limits<ll>::min());

    while(q--) {
        string qtype;
        cin >> qtype;
        ll qv;
        cin >> qv;

        if(qtype == "INS") {
            tree.insert(qv);
            cout << "INSERTED: " << qv << "\n";
        } else if(qtype == "IN") {
            cout << qv << " INCLUDED: " << (tree.find(qv) == nullptr ? "NO" : "YES") << "\n";
        } else {
            cout << qv << " LOWER BOUND: " << tree.lower_bound(qv) << "\n";
        }
    }

    cout << flush;

    return 0;
}