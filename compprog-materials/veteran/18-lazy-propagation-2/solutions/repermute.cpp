#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

vll invert(const vll& perm) {
    ll n = perm.size();

    vll res(n, 0ll);

    for(ll i = 0ll; i < n; i++) {
        res[perm[i]] = i;
    }

    return res;
}

class Tree {
    public:
        Tree *lt, *rt;
        ll l, r, k;
        vll cnt;

        // lazy[i] represents the *original* value of i before applying the updates
        // It turns out to be easier to combine updates this way
        vll lazy;
        bool marked = false; // I think you can actually get away with not using this "marked" flag, but ehh, it makes things marginally faster ^^

        Tree(ll a_l, ll a_r, ll a_k): lt(nullptr), rt(nullptr), l(a_l), r(a_r), k(a_k), cnt(a_k, 0ll), lazy(a_k, 0ll), marked(true) {
            for(ll i = 0ll; i < k; i++) {
                lazy[i] = i;
            }
        };

        void push_half(const vll& b) {
            vll nlazy(k, 0ll), ncnt(k, 0ll);
            for(ll i = 0; i < k; i++) {
                // the original value of i is b[i]
                // Therefore, the new count of i is count[b[i]]
                // since i was originally b[i].
                // Similarly, the new original value of i is lazy[b[i]]
                // since it was originally b[i] before applying the current update
                // This is quite confusing. I encourage you to think about this!
                nlazy[i] = lazy[b[i]];
                ncnt[i] = cnt[b[i]];
            }
            lazy = nlazy; cnt = ncnt;

            marked = true;
        }

        void push() {
            if(!marked) return;

            if(lt == nullptr) return;

            lt->push_half(lazy);
            rt->push_half(lazy);

            marked = false;
            for(ll i = 0ll; i < k; i++) lazy[i] = i;
        }

        void pull() {
            for(ll i = 0ll; i < k; i++) cnt[i] = lt->cnt[i] + rt->cnt[i];
        }

        ll range_sum() {
            ll ans = 0ll;
            for(ll i = 0ll; i < k; i++) ans += i * cnt[i];

            return ans;
        }

        void build(const vll& a) {
            if(l == r) {
                cnt[a[l]] = 1;
                return;
            }

            ll m = (l + r) >> 1ll;

            lt = new Tree(l, m, k);
            rt = new Tree(m + 1ll, r, k);

            lt->build(a);
            rt->build(a);

            pull();
        }

        ll query(ll ql, ll qr) {
            if(ql > r || qr < l) return 0ll;

            push();

            if(ql == l && qr == r) return range_sum();

            ll m = (l + r) >> 1ll;

            return lt->query(ql, min(m, qr)) + rt->query(max(m + 1ll, ql), qr);
        }

        void upd(ll ql, ll qr, const vll& b) {
            if(ql > r || qr < l) return;
            push();

            if(ql == l && qr == r) {
                push_half(b);
                return;
            }

            ll m = (l + r) >> 1ll;

            lt->upd(ql, min(qr, m), b);
            rt->upd(max(ql, m + 1ll), qr, b);

            pull();
        }
};

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    vll a(n, 0ll);
    for(ll& av : a) cin >> av;

    Tree tr(0ll, n - 1ll, k);
    tr.build(a);

    ll q;
    cin >> q;

    vll b(k, 0ll);

    string ignore_token;

    while(q--) {
        string qtype;
        cin >> qtype;

        if(qtype == "U") {
            ll ql, qr;
            cin >> ql >> qr;
            ql--; qr--;

            cin >> ignore_token;

            for(ll& bv : b) cin >> bv;

            /*
            You need to invert b because originally,
            b[i] represents the new value of i

            However, as you can see with our segtree implementation,
            the lazy updates are stored like so:
            lazy[i] represents the *original* value of i before the
            lazy updates were applied.

            In other words,
            lazy is a mapping from the new values to the old values,
            while b is a mapping from the old values to the new values

            Thus, for consistency, we have to invert permutation b so that
            it maps from new values to old values.
            */
            tr.upd(ql, qr, invert(b));

            cout << "U " << ql << " " << qr << "\n";
        } else {
            ll ql, qr;
            cin >> ql >> qr;
            ql--; qr--;

            cout << "Q " << ql << " " << qr << " = " << tr.query(ql, qr) << "\n";
        }
    }

    cout << "\n" << "FINAL ARRAY" << "\n";

    for(ll i = 0ll; i < n; i++) {
        cout << tr.query(i, i) << " ";
    }
    cout << "\n";
    cout << flush;

    return 0;
}