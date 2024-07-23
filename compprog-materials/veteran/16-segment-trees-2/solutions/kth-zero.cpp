#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define INF(type) numeric_limits<type>::max()
#define NINF(type) numeric_limits<type>::min()

class Tree {
    public:
        ll l, r;
        ll v;
        Tree *lt, *rt;

        Tree(ll a_l, ll a_r): l(a_l), r(a_r), v(0ll), lt(nullptr), rt(nullptr) {};

        void combine() {
            v = lt->v + rt->v;
        }

        void build(const vll& a) {
            if(l == r) {
                v = (a[l] == 0ll ? 1ll : 0ll);
                return;
            }

            ll m = (l + r) >> 1ll;

            lt = new Tree(l, m);
            rt = new Tree(m + 1, r);

            lt->build(a);
            rt->build(a);

            combine();
        }

        void upd(ll i, ll nv) {
            if(l == r) {
                v = (nv == 0ll ? 1ll : 0ll);
                return;
            }

            ll m = (l + r) >> 1ll;

            (i <= m ? lt : rt)->upd(i, nv);

            combine();
        }

        ll kth_zero(ll k) {
            if(v < k) return -1ll;
            if(l == r) return l;

            if(lt->v >= k) return lt->kth_zero(k);
            else return rt->kth_zero(k - lt->v);
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

        if(qtype == "Q") {
            ll k;
            cin >> k;

            cout << "INDEX: " << tr.kth_zero(k) << "\n"; 
        } else {
            ll i, nv;
            cin >> i >> nv;

            tr.upd(i, nv);
        }
    }

    cout << flush;

    return 0;
}