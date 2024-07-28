#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define INF(type) numeric_limits<type>::max()
#define NINF(type) numeric_limits<type>::min()

class Tree {
    public:
        Tree *lt, *rt;
        ll l, r;
        ll v;
        ll lazy;

        Tree(ll a_l, ll a_r): lt(nullptr), rt(nullptr), l(a_l), r(a_r), v(0ll), lazy(0ll) {};

        void push_half(ll n_lazy) {
            v += n_lazy * (r - l + 1ll);
            lazy += n_lazy;
        }

        void push() {
            if(lt != nullptr) { // ! no need to put && rt != nullptr because segtrees form a full binary tree
                lt->push_half(lazy);
                rt->push_half(lazy);
            }
            lazy = 0ll;
        }

        void pull() { // This is functionally the same as the "combine" function ^^
            v = lt->v + rt->v;
        }

        void build(const vll& a) {
            if(l == r) {
                v = a[l];

                return;
            }

            ll m = (l + r) >> 1ll;

            lt = new Tree(l, m);
            rt = new Tree(m + 1ll, r);

            lt->build(a);
            rt->build(a);

            pull();
        }

        void upd(ll ql, ll qr, ll incv) {
            if(ql > r || qr < l) return;
            push(); // Push any lazy updates to the children

            if(ql == l && qr == r) {
                // The query range completely contains the node range
                // Update this node then mark it as "in need of lazy updates"
                push_half(incv);
                return;
            }

            ll m = (l + r) >> 1ll;

            lt->upd(ql, min(qr, m), incv);
            rt->upd(max(ql, m + 1ll), qr, incv);

            pull();
        }

        ll query(ll ql, ll qr) {
            if(ql > r || qr < l) return 0ll;

            push(); // Push any lazy updates that need to be pushed

            if(ql == l && qr == r) return v;

            ll m = (l + r) >> 1ll;

            return lt->query(ql, min(m, qr)) + rt->query(max(m + 1, ql), qr);
        }
};

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;

    vll a(n, 0ll);

    for(ll& av : a) cin >> av;

    Tree tr(0ll, n - 1ll);

    tr.build(a);

    ll q;
    cin >> q;
    while(q--) {
        string qtype;
        cin >> qtype;

        if(qtype == "U") {
            ll ql, qr, qinc;
            cin >> ql >> qr >> qinc;
            ql--; qr--;

            cout << "UPDATING [ " << ql << ", " << qr << " ] += " << qinc << "\n";

            tr.upd(ql, qr, qinc);
        } else {
            ll ql, qr;
            cin >> ql >> qr;
            ql--; qr--;

            cout << "QUERY [ " << ql << ", " << qr << " ] = " << tr.query(ql, qr) << "\n"; 
        }
    }

    cout << flush;

    return 0;
}