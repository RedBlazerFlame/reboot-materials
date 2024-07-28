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

# Lazy Propagation 2: The Invariant Approach
## Veteran Track
## Gabee De Vera

---
<!-- _class: top -->

# Recall
- We learned how to implement Lazy Propagation last week!
- Lazy Propagation allows us to support *both* range queries *and* range updates in $O(\log n)$ time per query.
- Admittedly, Lazy Propagation is difficult not only to implement, but also to conceptualize. There are *many moving parts* :cry:
- Today, we will learn about an *alternative way to conceptualize Lazy Propagation*.

---
<!-- _class: top -->
# Recall
- Back when we were doing binary search, we encountered the **invariant-based approach**.
- When doing invariant-based binary search, you always think: "what remains true as I proceed with the binary search?"
- For example, when binary searching for the largest value in a sorted list $a$ that is less than or equal to $v$, we maintain two sets of indices $L$ and $R$, representing everything *we know* is less than or equal to $v$ and greater than $v$, respectively.
- Then, you can think of the invariant as "what remains true". In this case, the invariant is that everything in $L$ is less than or equal to $v$, and everything in $R$ is greater than $v$.

---
<!-- _class: top lead -->
# Recall

<br>
<br>
<br>

## Invariant-based binary search simply "updates" what we know to be true at each step of the algorithm

---
<!-- _class: lead -->
# Invariant-Based Lazy Propagation

---
<!-- _class: top -->
# Invariant-Based Lazy Propagation
- Applying the invariant-based approach to lazy propagation means considering *what remains true* after applying a range update.
- Again, recall that in a lazy propagating segment tree, we only ever need to worry about lazily updating a node if the query interval completely contains the node interval. Therefore, we only need to consider the case where we apply a range update over the whole interval.
- Thus, we can rephrase our goal as follows: Consider *what remains true* after applying a range upate *over the entire interval*.

---
<!-- _class: top -->
# Example: Counting 1s in a Range
- Consider the following problem. You have an array consisting of only $0$s and $1$s. You need to efficiently support the following two operations:
    1. Range sum
    1. Range NOT (i.e., all $0$s become $1$s and vice versa)

---
<!-- _class: top -->
# Example: Counting 1s in a Range
- Consider the following problem. You have an array consisting of only $0$s and $1$s. You need to efficiently support the following two operations:
    1. Range sum
    1. Range NOT (i.e., all $0$s become $1$s and vice versa)
- To solve this problem, we will consider *what remains true* after applying a range NOT over the entire interval.

---
<!-- _class: top -->
# Example: Counting 1s in a Range
- Notice that, to compute the range sum, you simply need to *count the number of $1$s in an interval*.
- What happens to the number of $1$s after negating all the bits in the array?

---
<!-- _class: top -->
# Example: Counting 1s in a Range
- Notice that, to compute the range sum, you simply need to *count the number of $1$s in an interval*.
- What happens to the number of $1$s after negating all the bits in the array? **The number of $1$s now becomes the original number of $0$s**.
- Therefore, if we *know* the original number of $0$s, we will also know the new number of $1$s.
- We can also store the number of $0$s for each node. Alternatively, you can notice that the number of $0$s for each node is simply the size of the interval minus the number of $1$s, since all elements are either $0$ or $1$.

---
<!-- _class: top -->
# Example: Counting 1s in a Range
- Therefore, to ensure that the number of $1$s remains correct after a range update, we do $(\#1) \leftarrow r - l + 1 - (\#1)$, where $(\#1)$ is the number of $1$s.
- For the lazy variable, you simply need to store a boolean of whether you need to negate the child nodes or not.

---
<!-- _class: top -->
# Implementation: Counting 1s in a Range
- TODO

---
<!-- _class: top -->

- TODO range sum with range repermutation

---

<!-- _class: top -->

# Homework

- Check the [Reboot Website](https://redblazerflame.github.io/reboot-materials/compprog-materials/veteran/18-lazy-propagation-2/) for the homework this week. This week, you wil only be assigned one problem, but it will be *very difficult*. In fact, you'll be tackling a previous IOI problem! Feel free to **collaborate and discuss with your fellow trainees**. You may also **ask for help from the trainers** and even **read the editorial (but only when you're really stuck)** :smile: