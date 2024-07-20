#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

class Tree {
    public:
        Tree *lt, *rt;
        ll l, r;
        ll v;

        Tree(ll a_l, ll a_r): l(a_l), r(a_r), v(0ll), lt(nullptr), rt(nullptr) {};

        void combine() {
            // Updates the value of the current node based on the value of its children
            v = lt->v + rt->v;
        }

        // Builds a segment tree from an array
        void build(const vll& a) {
            if(l == r) {
                // If the node contains a single index,
                // set the value of the node to the value of the array
                // at that index 
                v = a[l];
                return;
            }

            ll m = (l + r) >> 1ll; // Computing the middle/splitting point

            lt = new Tree(l, m);
            rt = new Tree(m + 1, r);

            lt->build(a);
            rt->build(a);

            combine();
        }

        ll query(ll ql, ll qr) {
            if(ql > r || qr < l) return 0ll;

            if(ql == l && qr == r) return v;

            ll m = (l + r) >> 1ll;

            return lt->query(ql, min(qr, m)) + rt->query(max(ql, m + 1), qr);
        }

        void upd(ll i, ll nv) {
            if(l == r && r == i) {
                v = nv;
                return;
            }

            ll m = (l + r) >> 1ll;

            if(i <= m) lt->upd(i, nv);
            else rt->upd(i, nv);

            combine();

            /*
            Note, you can also implement the last four lines as:
            (i <= ((l + r) >> 1ll) ? lt : rt)->upd(i, nv);
            combine();

            This is usually how I implement it, but if you're only
            starting out with segment trees, I don't recommend this
            since it's not as readable
            */
        }
};

int main() {
    ll n;
    cin >> n;

    vll a(n, 0ll);
    for(ll& av : a) cin >> av;

    Tree tr(0, n - 1);
    tr.build(a);

    ll q;
    cin >> q;

    while(q--) {
        string qtype;
        cin >> qtype;

        if(qtype == "U") {
            ll i, nv;
            cin >> i >> nv;

            i--;

            tr.upd(i, nv);
        } else if(qtype == "Q") {
            ll ql, qr;
            cin >> ql >> qr;
            ql--; qr--;

            cout << tr.query(ql, qr) << "\n";
        }
    }

    cout << flush;

    return 0;
}