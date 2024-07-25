#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
#define INF(type) numeric_limits<type>::max()
#define NINF(type) numeric_limits<type>::min()

const int NEG_INF = -1'000'000'000;

struct tree_data {
    int sub_sum;
    int pref_sum;
    int suff_sum;
    int tot_sum;
};

class Tree {
    public:
        int l, r;
        tree_data v;
        Tree *lt, *rt;

        Tree(int a_l, int a_r): l(a_l), r(a_r), v({0, 0, 0, 0}), lt(nullptr), rt(nullptr) {};

        inline tree_data combine_func(const tree_data& ld, const tree_data& rd) {
            return {max(ld.suff_sum + rd.pref_sum, max(ld.sub_sum, rd.sub_sum)), max(ld.pref_sum, ld.tot_sum + rd.pref_sum), max(rd.suff_sum, rd.tot_sum + ld.suff_sum), ld.tot_sum + rd.tot_sum};
        }

        inline void combine() {
            v = combine_func(lt->v, rt->v);
        }

        void set_v(int nv) {
            v.sub_sum = v.pref_sum = v.suff_sum = nv;
            v.tot_sum = nv;
        }

        void build(const vi& a) {
            if(l == r) {
                set_v(a[l]);
                return;
            }

            ll m = (l + r) >> 1;

            lt = new Tree(l, m);
            rt = new Tree(m + 1, r);

            lt->build(a);
            rt->build(a);

            combine();
        }

        void upd(int i, int nv) {
            if(l == r) {
                set_v(nv);
                return;
            }

            int m = (l + r) >> 1;

            (i <= m ? lt : rt)->upd(i, nv);

            combine();
        }

        tree_data query(int ql, int qr) {
            if(ql > r || qr < l) return {NEG_INF, NEG_INF, NEG_INF, 0};

            if(l == r) return v;

            int m = (l + r) >> 1;

            return combine_func(lt->query(ql, min(qr, m)), rt->query(max(ql, m + 1), qr));
        }
};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vi a(n, 0);
    for(int& av : a) cin >> av;

    Tree tr(0, n - 1);
    tr.build(a);

    int q;
    cin >> q;

    while(q--) {
        string qtype;
        cin >> qtype;

        if(qtype == "0") {
            int i, nv;
            cin >> i >> nv;
            i--;

            tr.upd(i, nv);
        } else {
            int ql, qr;
            cin >> ql >> qr;
            ql--; qr--;

            tree_data res = tr.query(ql, qr);

            cout << res.sub_sum << "\n";
        }
    }

    cout << flush;
    return 0;
}