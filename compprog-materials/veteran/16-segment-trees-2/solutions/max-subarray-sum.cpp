#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define INF(type) numeric_limits<type>::max()
#define NINF(type) numeric_limits<type>::min()

const ll NEG_INF = -1'000'000'000'000'000'000ll;

struct tree_data {
    ll sub_sum;
    ll pref_sum;
    ll suff_sum;
    ll tot_sum;
};

class Tree {
    public:
        ll l, r;
        tree_data v;
        Tree *lt, *rt;

        Tree(ll a_l, ll a_r): l(a_l), r(a_r), v({0ll, 0ll, 0ll, 0ll}), lt(nullptr), rt(nullptr) {};

        tree_data combine_func(const tree_data& ld, const tree_data& rd) {
            return {max(ld.suff_sum + rd.pref_sum, max(ld.sub_sum, rd.sub_sum)), max(ld.pref_sum, ld.tot_sum + rd.pref_sum), max(rd.suff_sum, rd.tot_sum + ld.suff_sum), ld.tot_sum + rd.tot_sum};
        }

        void combine() {
            v = combine_func(lt->v, rt->v);
        }

        void set_v(ll nv) {
            v.sub_sum = v.pref_sum = v.suff_sum = nv;
            v.tot_sum = nv;
        }

        void build(const vll& a) {
            if(l == r) {
                set_v(a[l]);
                return;
            }

            ll m = (l + r) >> 1ll;

            lt = new Tree(l, m);
            rt = new Tree(m + 1ll, r);

            lt->build(a);
            rt->build(a);

            combine();
        }

        void upd(ll i, ll nv) {
            if(l == r) {
                set_v(nv);
                return;
            }

            ll m = (l + r) >> 1ll;

            (i <= m ? lt : rt)->upd(i, nv);

            combine();
        }

        tree_data query(ll ql, ll qr) {
            if(ql > r || qr < l) return {NEG_INF, NEG_INF, NEG_INF, 0ll};

            if(l == r) return v;

            ll m = (l + r) >> 1ll;

            return combine_func(lt->query(ql, min(qr, m)), rt->query(max(ql, m + 1ll), qr));
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

        if(qtype == "U") {
            ll i, nv;
            cin >> i >> nv;
            i--;

            tr.upd(i, nv);
        } else {
            ll ql, qr;
            cin >> ql >> qr;
            ql--; qr--;

            tree_data res = tr.query(ql, qr);

            cout << "MAX_SUM[ " << ql + 1ll << ", "  << qr + 1ll << " ] = " << res.sub_sum << "\n";
        }
    }

    cout << flush;
    return 0;
}