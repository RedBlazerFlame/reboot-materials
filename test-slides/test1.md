---
theme: default
paginate: true
marp: true
footer: '**Reboot *2024***'
style: |
    pre, code {
        background-color: #dbd4c4;
    }
    pre {
        filter: invert(100%);
    }
---
<style>
    section.lead {
        text-align: center;
    }

    .normal {
        text-align: initial;
    }
</style>

<!-- _class: lead -->

# Gabee De Vera makes a Marp Slide
## Reboot 2024 Edition
:smile:

---

# A Wonderful Header
The time complexity of computing the range sum from a persistent segment tree is $O(\log n)$, while the auxiliary memory usage is $O(\log n)$ per query. While this memory usage is acceptable for most tasks, some problems tend to have tight bounds that require tweaking of the constant factor.

$$9 + 10 = 21$$
$$\begin{equation}\left(G, \oplus_1\right) \equiv \left(H, \oplus_2\right) := \exists f: G \to H\  \forall x, y \in G \left(f(x \oplus_1 y) = f(x) \oplus_2 f(y)\right)\end{equation}$$

---

# One
## Two
### Three
#### Four
##### Five
###### Six

---
# Bullet list

- One
- Two
- Three

---

# Fragmented list

* One
* Two

Insertion sort

* Three

Ano natsu no itsuka wa!! wwwww

---
# Ordered list

1. Armin
2. Levi
3. Hange
4. Erwin

---

# Fragmented list

1) MonoD
2) DoubleD
3) TripleD

---

# I love Code

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Tree {
    ll l, r;
    Tree* lt;
    Tree* rt;
    ll v;
    Tree(ll a_l, ll a_r): l(a_l), r(a_r), lt(nullptr), rt(nullptr), v(0) {};
    // ...
}
int main() {
    Tree* tr = new Tree();
    return 0;
}
```

---
# Attachments
- [My Code](main.cpp)

---
<!-- _class: lead -->
# Follow your Dreams

![width:800px](follow-your-dreams.png)
