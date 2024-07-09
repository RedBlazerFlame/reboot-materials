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
    @import "../../../slide.css";
</style>

<!-- _class: lead -->

# Binary Search 2
## Bootcamp Track
## Gabee De Vera

---
<!-- _class: lead -->

# Computing $\left\lfloor\sqrt{N}\right\rfloor$

---
<!-- _class: top -->

# Computing $\left\lfloor\sqrt{N}\right\rfloor$

- Suppose that you want to find $\left\lfloor\sqrt{N}\right\rfloor$ quickly, in $O(\log N)$ time *without* using floating point numbers.

---
<!-- _class: top -->

# Computing $\left\lfloor\sqrt{N}\right\rfloor$

- Suppose that you want to find $\left\lfloor\sqrt{N}\right\rfloor$ quickly, in $O(\log N)$ time *without* using floating point numbers.
- Let $k = \left\lfloor\sqrt{N}\right\rfloor$. Clearly, $k^2 \le N$. Thus, $k$ is the largest integer such that $k^2 \le N$.
- However, we can find this using binary search!
- Let $L$ be the set of numbers $k$ such that $k^2 \le N$, and $R$ be the set of numbers $k$ such that $k^2 \gt N$. Then, the answer is the largest value in the set $L$.

---
<!-- _class: top -->

# Computing $\left\lfloor\sqrt{N}\right\rfloor$

- Here's the implementation in C++

```c++
int n;
cin >> n;
int l = 0, r = n + 1;
while(r - l > 1) {
    int m = (l + r) >> 1;
    if(m * m <= n) l = m;
    else r = m;
}
cout << l << endl;
```

---
<!-- _class: top -->

# Computing $\left\lfloor\sqrt[3]{N}\right\rfloor$

- Computing $\left\lfloor\sqrt[3]{N}\right\rfloor$ can also be done similarly. This time, we want to find the largest integer $k$ such that $k^3 \le N$

```c++
int n;
cin >> n;
int l = 0, r = n + 1;
while(r - l > 1) {
    int m = (l + r) >> 1;
    if(m * m * m <= n) l = m;
    else r = m;
}
cout << l << endl;
```

---
<!-- _class: top -->

# A Generalization

- In general, to find the largest number $k$ that satisfies $f(k) \le N$, where $f$ is some *monotonically increasing function* (i.e., it does not decrease as $k$ increases), we use,

```c++
int n;
cin >> n;
int l = 0, r = n + 1;
while(r - l > 1) {
    int m = (l + r) >> 1;
    if(f(m) <= n) l = m;
    else r = m;
}
cout << l << endl;
```

- In fact, $f(m) \le n$ is known as a *predicate function*.

---

<!-- _class: lead -->
# Predicate Function

---

<!-- _class: top -->
# Predicate Function

- A **predicate function** is a function that, given a certain value $x$ (usually an integer), returns a boolean.
- For example, $g(x) := x \le 10$ is a predicate function, since $x$ can be an integer, and $g$ returns a boolean.
- Some other predicate functions that we've seen include,

$$g_1(x) := a_x \le k$$
$$g_2(x) := x^2 \le k$$
$$g_3(x) := x^3 \le k$$

---

<!-- _class: top -->

# Binary Search with Predicate Functions

- In fact, **binary search** can be generalized to work with *more kinds of* predicate functions.
- That being said, not all types of predicate functions work for binary search.
- The predicate function must return true for inputs $x \le k$ and return false for inputs $x \gt k$ for some $k$. (It could also return false for $x \le k$ and true for $x \gt k$. In this case, you just take the logical NOT of your function)
- These kinds of predicate functions are known as **monotonic** predicate functions.

---

<!-- _class: top -->

# Binary Search with a Monotonic Predicate Function $g$

- In its full generality, this is what the binary search algorithm looks like:

```c++
int l = MINV - 1, r = MAXV + 1;
while(r - l > 1) {
    int m = (l + r) >> 1;
    if(g(m)) l = m;
    else r = m;
}
```

- Its time complexity is $O(g \log N)$, where $N$ is the size of the initial interval, and $g$ is the time it takes to execute the function $g$.

---

<!-- _class: top -->
# Two-Liner Binary Search

- You can push this even further using the ternary operator. Here's an implementation of binary search in two lines of C++:

<br>
<br>

```c++
int l = MINV - 1, r = MAXV + 1;
while(r - l > 1) (g((l + r) >> 1) ? l : r) = (l + r) >> 1;
```

---

<!-- _class: top -->

# Binary Searching for the Answer

- A common pattern in CompProg is to use *binary search* to find an optimal value in certain optimization problems.
- Instead of directly computing the optimal value $v$, we instead consider a similar problem: is there a configuration that solves the problem with value $v$ or less?
- Let $\text{good}(v)$ be true if there is a configuration that solves the problem with value $v$ or less
- Then, $\text{good}(v)$ is monotonic, and we can solve this problem with binary search in $O(f(N) \cdot \log N)$, where $f(N)$ is the time complexity of $\text{good}(v)$.

---

<!-- _class: top -->

# Binary Searching for the Answer

- Consider, for instance, the following optimization problem (taken from https://cp-algorithms.com/num_methods/binary_search.html): You are given an array $a_i$ composed of $n$ integers. What is the largest floored average value over all possible subarrays? Formally, for all $0 \le l \le r \le n - 1$ satisfying $r - l + 1 \ge x$, what is the largest value of $\left\lfloor\frac{\sum_{i = l}^{r} a_i}{r - l + 1}\right\rfloor$?
- Constraints: $1 \le a_i \le 10^9$, $1 \le n \le 2 \cdot 10^{5}$, $1 \le x \le n$
- First, note that the brute force algorithm, which simply goes through all possible subarrays is $O(n^3)$. This can be further optimized to $O(n^2)$ using the previously discussed prefix sum technique.
- However, our goal is to find something that is faster than quadratic -- i.e., *subquadratic*. Is such an algorithm possible?

---

<!-- _class: top -->

# Binary Searching for the Answer
- Let $\left\lfloor\frac{\sum_{i = l}^{r} a_i}{r - l + 1}\right\rfloor = k$ be the answer. We will binary search for the proper $k$.
- Start with a candidate value for $k$, $k'$. Then, we will attempt to find a subarray of $a$ such that $\left\lfloor\frac{\sum_{i = l}^{r} a_i}{r - l + 1}\right\rfloor \ge k'$. Define a function $g(k')$. If there exists a subarray that satisfies the constraint, then $g(k') = \text{true}$. Else, $g(k') = \text{false}$.
- We can use binary search on the answer to find the answer in $O(f(n) \cdot \log\left(\text{maximum possible sum}\right))$, where $f(n)$ is the time complexity of running function $g$. In practice, a value of around $10^{18}$ suffices for the initial upper bound of your binary search, but this of course *depends on your problem*.

---

<!-- _class: top -->

# Binary Searching for the Answer

- Now, we've simplified the optimization problem to the following decision problem: Is there a subarray of length at least $r - l + 1 \ge x$ that satisfies $\left\lfloor\frac{\sum_{i = l}^{r} a_i}{r - l + 1}\right\rfloor \ge k'$?

---

<!-- _class: top -->

# Binary Searching for the Answer

- Now, we've simplified the optimization problem to the following decision problem: Is there a subarray of length at least $r - l + 1 \ge x$ that satisfies $\left\lfloor\frac{\sum_{i = l}^{r} a_i}{r - l + 1}\right\rfloor \ge k'$?
- To solve this, we can perform some simplifications:
$$\frac{\sum_{i = l}^{r} a_i}{r - l + 1} \ge k'$$
$$\sum_{i = l}^{r} a_i \ge k' (r - l + 1)$$
$$\sum_{i = l}^{r} \left(a_i - k'\right) \ge 0$$

---

<!-- _class: top -->

# Binary Searching for the Answer
$$\sum_{i = l}^{r} \left(a_i - k'\right) \ge 0$$
- Thus, we only need to check if there is a subarray of the array that satisfies the constraint above.
- Consider the array $b_i = a_i - k'$ (which could be computed in $O(n)$). Then, the condition above becomes,

$$\sum_{i = l}^{r} b_i \ge 0$$

- Therefore, we only need to determine whether there is a subarray of $b$ of length at least $r - l + 1 \ge x$ whose sum is nonnegative.

---

<!-- _class: top -->

# Binary Searching for the Answer
- To calculate a subarray sum over $b$ quickly, we can use *prefix sums*. Consider the prefix sum array $\sum b$ of length $n + 1$. Here, $\left(\sum b\right)[i] := \sum_{k = 0}^{i - 1}b[k]$.
- Then, $\sum_{i = l}^{r} b[i] = \left(\sum b\right)[r + 1] - \left(\sum b\right)[l]$.
- We thus want to find two indices $r$ and $l$  satisfying $r - l + 1 \ge x$ such that $\left(\sum b\right)[r + 1] - \left(\sum b\right)[l] \ge 0$.
- With the substitution $u = r + 1$, this is the same as finding two indices $u$ and $l$ in the array $\left(\sum b\right)$ such that $u - l \ge x$ and $\left(\sum b\right)[u] \ge \left(\sum b\right)[l]$.
- Therefore, if we can find such a pair of indices quickly, we can solve the original problem quickly!

---

<!-- _class: top -->

# Binary Searching for the Answer

- The idea is to *reduce* this problem to a problem of range maximums over a static array, as follows:
- For every index $l$, consider all indices $i \ge l + x$. If there is at least one value $i$ such that $\left(\sum b\right)[i] \ge \left(\sum b\right)[l]$.
- This value $i$ only exists if the maximum of $\left(\sum b\right)[l + x], \left(\sum b\right)[l + x + 1], \left(\sum b\right)[l + x + 2], \left(\sum b\right)[l + x + 3], ..., \left(\sum b\right)[n]$ is $\ge \left(\sum b\right)[l]$.
- If you compute this naively, you will arrive at a $O(n^2 \log n)$ solution for the problem. That's rather unsatisfying, since our best algorithm so far is $O(n^2)$.

---

<!-- _class: top -->

# Binary Searching for the Answer

- To speed this up, notice that the step where we take the maximum of $\left(\sum b\right)[l + x], \left(\sum b\right)[l + x + 1], \left(\sum b\right)[l + x + 2], \left(\sum b\right)[l + x + 3], ..., \left(\sum b\right)[n]$ is slow.
- Observe, however, that we are taking the maximum over a *suffix* of the original array.
- We fortunately can precompute the maximum for every possible suffix in $O(n)$ using a variation of the previously discussed prefix sum technique!
- Therefore, since we iterate through all values of $l$ (there are $O(n)$ of them), then find the suffix maximum for each $l$ in $O(1)$ through precomputation, the total complexity of the function $\text{g}$ is $O(n)$.

---

<!-- _class: top -->

# Binary Searching for the Answer

- This gives us a final complexity of $O(n \log n)$, which is fast enough, yay! :partying_face:
- The implementation for this problem is quite long. Check the GitHub for the implementation: [Implementation](https://github.com/RedBlazerFlame/reboot-materials/tree/main/compprog-materials/bootcamp/12-binary-search-2/solutions/meansummain.cpp)
- You may also want to see the [implementation for the brute force](https://github.com/RedBlazerFlame/reboot-materials/tree/main/compprog-materials/bootcamp/12-binary-search-2/solutions/meansumbrute.cpp) for this problem as well :eyes:

---

<!-- _class: top -->

# Homework

- Check the [Reboot Website](https://redblazerflame.github.io/reboot-materials/compprog-materials/bootcamp/12-binary-search-2) for your homework this week. As usual, feel free to ask for help from your fellow trainees or from the trainers through the Discord server. We're always here to help :smile: