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
        ll mv, mvc;
        Tree *lt, *rt;
    
        Tree(ll a_l, ll a_r): l(a_l), r(a_r), mv(0ll), mvc(a_r - a_l + 1ll), lt(nullptr), rt(nullptr) {};

        inline pll combine_func(ll m1, ll m1c, ll m2, ll m2c) {
            if(m1 > m2) return {m1, m1c};
            if(m1 < m2) return {m2, m2c};
            return {m1, m1c + m2c};
        }

        void combine() {
            auto [a_mv, a_mvc] = combine_func(lt->mv, lt->mvc, rt->mv, rt->mvc);
            
            mv = a_mv;
            mvc = a_mvc;
        }
        
        void build(const vll& a) {
            if(l == r) {
                mv = a[l];
                mvc = 1ll;
                return;
            }
            
            ll m = (l + r) >> 1ll;
            
            lt = new Tree(l, m);
            rt = new Tree(m + 1, r);
            
            lt->build(a);
            rt->build(a);
            combine();
        }
        
        pll query(ll ql, ll qr) {
            if(ql > r || qr < l) return {NINF(ll), r - l + 1ll};
            
            if(ql == l && qr == r) return {mv, mvc};
            
            ll m = (l + r) >> 1ll;
            
            pll lr = lt->query(ql, min(qr, m));
            pll rr = rt->query(max(ql, m + 1ll), qr);
            
            combine();
            
            return combine_func(lr.first, lr.second, rr.first, rr.second);
        }
        
        void upd(ll i, ll nv) {
            if(l == r && r == i) {
                mv = nv;
                return;
            }
            
            ll m = (l + r) >> 1ll;
            
            (i <= m ? lt : rt)->upd(i, nv);
            
            combine();
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
            ll ql, qr;
            cin >> ql >> qr;
            ql--; qr--;

            auto [mv, mvc] = tr.query(ql, qr);

            cout << "MAX: " << mv << ", COUNT: " << mvc << "\n"; 
        } else {
            ll i, nv;
            cin >> i >> nv;
            i--;

            tr.upd(i, nv);
        }
    }

    cout << flush;

    return 0;
}