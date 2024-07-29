#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

class Tree {
    public:
        Tree *lt, *rt;
        ll l, r;
        ll v;
        bool marked;

        Tree(ll a_l, ll a_r): lt(nullptr), rt(nullptr), l(a_l), r(a_r), v(0ll), marked(false) {};

        void push_half() {
            v = (r - l + 1ll) - v;
            marked = !marked;
        }

        void push() {
            if(!marked) return;
            if(lt == nullptr) return;

            lt->push_half();
            rt->push_half();

            marked = false;
        }

        void pull() {
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

        ll query(ll ql, ll qr) {
            if(ql > r || qr < l) return 0ll;

            push();

            if(ql == l && qr == r) return v;

            ll m = (l + r) >> 1ll;

            return lt->query(ql, min(qr, m)) + rt->query(max(ql, m + 1ll), qr);
        }

        void upd(ll ql, ll qr) {
            if(ql > r || qr < l) return;

            push();

            if(ql == l && qr == r) {
                push_half();
                return;
            }

            ll m = (l + r) >> 1ll;

            lt->upd(ql, min(qr, m));
            rt->upd(max(ql, m + 1ll), qr);

            pull();
        }
};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

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

        ll ql, qr;
        cin >> ql >> qr;
        ql--; qr--;

        if(qtype == "Q") {
            cout << "tr[ " << ql + 1ll << ", " << qr + 1ll << " ] = " << tr.query(ql, qr) << "\n";
        } else {
            tr.upd(ql, qr);
            cout << "UPD " << ql + 1ll << " " << qr + 1ll << "\n";
        }
    }

    cout << flush;

    return 0;
}