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

# Probset: Proving Greedy Algorithms
## Veteran Track
## Gabee De Vera

---

<!-- _class: top -->

<style scoped>
    h1:first-of-type {
        text-align: center;
    }
</style>

# Problem 1

In [**Linova and Kingdom**](https://codeforces.com/problemset/problem/1336/A), show that if a node is picked, then everything in its subtree must be picked. No need to be overly formal. As long as you convince me, it's fine ^^

---

<!-- _class: top -->

<style scoped>
    h1:first-of-type {
        text-align: center;
    }
</style>

# Problem 2

There are $n$ chess matches to be scheduled in the PSHS-MC ASTB. Each chess match has a starting time $s_i$ and an ending time $e_i$. Two chess matches $i$ and $j$ are said to be in conflict if they occur simultaneously for some time $t$. Specifically, they are in conflict if $[s_i, e_i] \cap [s_j, e_j] \neq \varnothing$ (you may clarify this in the Discord server).

You must schedule a subset of these chess matches such that none of them are in conflict with one another. What is the maximum number of chess matches that you could schedule?

Your task: **Describe** an algorithm that solves this problem in linear or linearithmic ($O(n \log n)$) time. Then, prove the correctness of your algorithm using the ideas discussed in this week's lesson. You may refer to section 3 of [this learning guide](https://redblazerflame.github.io/reboot-materials/compprog-materials/noiph-modules/algo2.pdf).