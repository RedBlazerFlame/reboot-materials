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
        ll lazy;
        bool marked;
        Tree *lt, *rt;
    
        Tree(ll a_l, ll a_r): l(a_l), r(a_r), mv(0ll), mvc(a_r - a_l + 1ll), lazy(0ll), marked(false), lt(nullptr), rt(nullptr) {};

        inline pll combine_func(ll m1, ll m1c, ll m2, ll m2c) {
            if(m1 < m2) return {m1, m1c};
            if(m1 > m2) return {m2, m2c};
            return {m1, m1c + m2c};
        }

        void combine() {
            pll combine_res = combine_func(lt->mv, lt->mvc, rt->mv, rt->mvc);
            ll a_mv = combine_res.first, a_mvc = combine_res.second;
            
            mv = a_mv;
            mvc = a_mvc;
        }
    
        void push_half(ll upd) {
            mv += upd;
            marked = true;
            lazy += upd;
        }
    
        void push() {
            if(!marked) return;
            if(lt != nullptr) {
                lt->push_half(lazy);
                rt->push_half(lazy);
            }
            marked = false;
            lazy = 0ll;
        }
        
        void build() {
            if(l == r) {
                mv = 0ll;
                mvc = 1ll;
                return;
            }
            
            ll m = (l + r) >> 1ll;
            
            lt = new Tree(l, m);
            rt = new Tree(m + 1, r);
            
            lt->build();
            rt->build();
            combine();
        }
        
        pll query(ll ql, ll qr) {
            if(ql > r || qr < l) return {INF(ll), r - l + 1ll};
            push();
            
            if(ql == l && qr == r) return {mv, mvc};
            
            ll m = (l + r) >> 1ll;
            
            pll lr = lt->query(ql, min(qr, m));
            pll rr = rt->query(max(ql, m + 1ll), qr);
            
            combine();
            
            return combine_func(lr.first, lr.second, rr.first, rr.second);
        }
        
        void upd(ll ql, ll qr, ll inc) {
            if(ql > r || qr < l) return;
            
            push();
            
            if(ql == l && qr == r) {
                push_half(inc);
                push();
                return;
            }
            
            ll m = (l + r) >> 1ll;
            
            lt->upd(ql, min(qr, m), inc);
            rt->upd(max(ql, m + 1), qr, inc);
            
            combine();
        }
};

pll intersect(ll v11, ll v12, ll v21, ll v22) {
    return {max(v11, v21), min(v12, v22)};
}

struct rect_upd {
    ll t;
    ll y1, y2;
    ll delta;
};

const ll SHIFT = 1000002ll;
const ll SEGTREE_SZ = 3000010ll;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll n;
    cin >> n;
    
    vector<rect_upd> rects;
    
    ll xmn = NINF(ll), xmx = INF(ll), ymn = NINF(ll), ymx = INF(ll);
    for(ll i = 0ll; i < n; i++) {
        ll x, y, w, h;
        cin >> x >> y >> w >> h;
        x += SHIFT;
        y += SHIFT;
        rects.push_back({x, y, y + h - 1ll, 1ll});
        rects.push_back({x + w, y, y + h - 1ll, -1ll});
        
        pll xintres = intersect(xmn, xmx, x, x + w - 1ll);
        ll nxmn = xintres.first, nxmx = xintres.second;
        pll yintres = intersect(ymn, ymx, y, y + h - 1ll);
        ll nymn = yintres.first, nymx = yintres.second;
        
        xmn = nxmn;
        ymn = nymn;
        xmx = nxmx;
        ymx = nymx;
    }
    
    sort(rects.begin(), rects.end(), [](rect_upd r1, rect_upd r2) {return r1.t < r2.t;});
    
    ll intersect_area = max(xmx - xmn + 1ll, 0ll) * max(ymx - ymn + 1ll, 0ll);
    
    ll union_area = 0ll;
    
    Tree tr(0ll, SEGTREE_SZ - 1ll);
    tr.build();
    
    ll ptr = 0ll;
    ll rect_upd_size = rects.size();
    for(ll x = 0ll; x < (SEGTREE_SZ << 1ll); x++) {
        while(ptr < rect_upd_size && rects[ptr].t == x) {
            // Update ptr
            rect_upd rect = rects[ptr];
            tr.upd(rect.y1, rect.y2, rect.delta);
            ptr++;
        }
        
        pll qres = tr.query(0ll, SEGTREE_SZ - 1ll);
        ll mn = qres.first, mnc = qres.second;
        
        union_area += SEGTREE_SZ - mnc;
    }
    
    cout << intersect_area << " " << union_area << endl;
    
    return 0;
}
