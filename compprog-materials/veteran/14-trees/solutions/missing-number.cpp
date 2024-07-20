#include<bits/stdc++.h>
using namespace std;

/*========================
BST IMPLEMENTATION ZONE!
Implement your BST here!

NO NEED TO MAKE IT
SELF-BALANCING

I randomize the inputs for
you before inserting it
into the BST :))


Instructions:
The constructor must
take in a value "v", which
is the value of the node

You must also implement a
"insert" function that,
given a new number,
inserts it into the BST
(you may opt to return
a reference to the created
node or leave the insert
function "void")

Then, you must implement
a "find" function that,
given a value, determines
whether it is in the BST.
If it is, then it returns
a reference to the BST
node with that value
(use the keyword "this"
to return a pointer to
the current Node).
Otherwise, it returns
nullptr if the given value
is not in the BST.

Note on the Problem:
The problem asks you
to find the missing number
given a list of n-1
numbers from 1 to n.

You can solve this with a
BST by inserting all
values into the BST and
determining, for each
integer from 1 to n,
whether the value is in
the BST or not.
========================*/
class BST {
    public:
        BST* lt, *rt;
        int v;

        BST(int a_v): v(a_v), lt(nullptr), rt(nullptr) {};

        BST* insert(int nv) {
            BST*& insert_dir = (nv <= v ? lt : rt);
            if(insert_dir == nullptr) {
                insert_dir = new BST(nv);
                return insert_dir;
            } else {
                return insert_dir->insert(nv);
            }
        }

        BST* find(int qv) {
            if(v == qv) return this;

            if((qv < v && lt == nullptr) || (qv > v && rt == nullptr)) return nullptr;
            return (qv < v ? lt : rt)->find(qv);
        }
};

// ! IGNORE EVERYTHING BELOW THIS LINE!!

/*========================
DRIVER CODE
Edit at your own risk :)

Template by: Gabee De Vera
========================*/
std::random_device dev;
std::mt19937 rng(dev());

pair<int, int> rand_dist_pair(std::uniform_int_distribution<std::mt19937::result_type>& dist) {
    int i, j;

    do {
        i = dist(rng);
        j = dist(rng);
    } while(i == j);

    return {i, j};
}

// If you're reading this, it's necessary to randomize the input first since, otherwise,
// the non-balancing BST may degenerate to O(n^2) in the worst-case
void shuffle_vec(vector<int>& v) {
    int n = v.size();

    std::uniform_int_distribution<std::mt19937::result_type> uniform_rand(0, n - 1);

    for(int rep = 0; rep < n; rep++) {
        auto [i, j] = rand_dist_pair(uniform_rand);

        swap(v[i], v[j]);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    BST tree(numeric_limits<int>::min());

    vector<int> vals(n - 1, -1);

    for(int& v : vals) {
        cin >> v;
    }

    if(n > 2) {
        shuffle_vec(vals);
    }

    for(int v : vals) {
        tree.insert(v);
    }

    for(int i = 1 ; i <= n; i++) {
        if(tree.find(i) == nullptr) cout << i << "\n";
    }

    cout << flush;

    return 0;
}