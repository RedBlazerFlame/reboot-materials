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

# Want to Buff your Segtree?

---
<!-- _class: lead -->

# Now you Can!

---
<!-- _class: lead -->

# Introducing...

---
<!-- _class: lead -->

# Lazy Propagation 1
## Veteran Track
## Gabee De Vera

---
<!-- _class: top -->

# Recall
- So far, we know how to implement a segtree that supports (in $O(\log n)$):
    1. **Range** queries, and
    1. **Point** updates

---
<!-- _class: top -->

# Recall
- So far, we know how to implement a segtree that supports (in $O(\log n)$):
    1. **Range** queries, and
    1. **Point** updates

- Recall that, when we say *point* update, we are referring to updating a *single* position in a segment tree.

---
<!-- _class: top -->

# Recall
- So far, we know how to implement a segtree that supports (in $O(\log n)$):
    1. **Range** queries, and
    1. **Point** updates

- Recall that, when we say *point* update, we are referring to updating a *single* position in a segment tree.
- A natural next question to ask is... can we handle both **Range Queries and Range Updates**?

---
<!-- _class: top -->

# What is a Range Update?
- A **Range Update** is an update over an *entire interval*.
- For example, given the (0-indexed) list $[3, 1, 4, 1, 5, 9, 2]$, increasing all elements from index $l = 1$ to index $r = 3$ by $2$ gives: $[3, 3, 6, 3, 5, 9, 2]$.
- This is an example of a *range increment*.
- Our goal today is to make a Range Updating and Range Querying (RURQ) Segment Tree.

---
<!-- _class: top -->

# PURQ $\rightarrow$ RUPQ

- Before tackling range queries and range updates, what if we try to tackle *point* queries and range updates first?
- The trick to handling these types of queries is to *somehow reduce it to range updates and point queries (RUPQ)* (which we can handle using a regular segtree)

---
<!-- _class: top -->

# PURQ $\rightarrow$ RUPQ

- Before tackling range queries and range updates, what if we try to tackle *point* queries and range updates first?
- The trick to handling these types of queries is to *somehow reduce it to range updates and point queries (RUPQ)* (which we can handle using a regular segtree)
- Let us consider a basic example: range increments and point queries

---
<!-- _class: top -->

# PURQ $\rightarrow$ RUPQ
- A range increment refers to adding a fixed value over a subinterval and querying for the value at a point.
- For example, say we have the array $a = [3, 1, 4, 1, 5, 9, 2]$.
- Then, let's say we increase the interval $l = 1$ to $r = 5$ by 2. The new array would be $a' = [3, 3, 5, 3, 7, 11, 2]$.
- Now, consider the array containing the differences between successive elements.
- Formally, let $\Delta l$ refer to the array that satisfies $\Delta l[i] = l[i] - l[i - 1]$ (assume $l[-1] = 0$) for all indices $i$.

---
<!-- _class: top -->

# PURQ $\rightarrow$ RUPQ
- Now, consider again the original array $a = [3, 1, 4, 1, 5, 9, 2]$ and the new array $a' = [3, 3, 5, 3, 7, 11, 2]$. What do $\Delta a$ and $\Delta a'$ look like?

---
<!-- _class: top -->

# PURQ $\rightarrow$ RUPQ
- Now, consider again the original array $a = [3, 1, 4, 1, 5, 9, 2]$ and the new array $a' = [3, 3, 5, 3, 7, 11, 2]$. What do $\Delta a$ and $\Delta a'$ look like?

$$\Delta a = [3, -2, 3, -3, 4, 4, -7]$$
$$\Delta a = [3, 0, 3, -3, 4, 4, -9]$$

---
<!-- _class: top -->

# PURQ $\rightarrow$ RUPQ
- Notice anything interesting with these two arrays?

$$\Delta a = [3, -2, 3, -3, 4, 4, -7]$$
$$\Delta a = [3, 0, 3, -3, 4, 4, -9]$$

---
<!-- _class: top -->

# PURQ $\rightarrow$ RUPQ
- Notice anything interesting with these two arrays?

$$\Delta a = [3, \color{red}-2\color{black}, 3, -3, 4, 4, \color{red}-7\color{black}]$$
$$\Delta a = [3, \color{red}0\color{black}, 3, -3, 4, 4, \color{red}-9\color{black}]$$

- Yep! They differ at at most *two* points!
- Therefore, a *range* increment over $a$ corresponds to *point* updates on $\Delta a$ :exploding_head:

---
<!-- _class: top -->

# PURQ $\rightarrow$ RUPQ
- Now, how do we handle *point* queries? Well, this turns out to be quite simple!
- Again, recall that $\Delta a[i] = a[i] - a[i - 1]$. Consider the following sum:

$$\sum_{k = 0}^{k = i} \Delta a[k]$$

---
<!-- _class: top -->

# PURQ $\rightarrow$ RUPQ
- Now, how do we handle *point* queries? Well, this turns out to be quite simple!
- Again, recall that $\Delta a[i] = a[i] - a[i - 1]$. Consider the following sum:

$$\sum_{k = 0}^{k = i} \Delta a[k]$$

---
<!-- _class: top -->

# PURQ $\rightarrow$ RUPQ

- This simplifies to:

$$\begin{align}\sum_{k = 0}^{k = i} \Delta a[k] & = \sum_{k = 0}^{k = i}a[k] - a[k - 1]\\ 
& = \sum_{k = 0}^{k = i}a[k] - \sum_{k = 0}^{k = i}a[k - 1]\\ 
& = \sum_{k = 0}^{k = i}a[k] - \sum_{k = -1}^{k = i - 1}a[k]\\ 
& = a[i] - a[-1] + \sum_{k = 0}^{k = i - 1}a[k] - \sum_{k = 0}^{k = i - 1}a[k]\\ \end{align}$$

---
<!-- _class: top -->

# PURQ $\rightarrow$ RUPQ

- This simplifies to:

$$\begin{align}\sum_{k = 0}^{k = i} \Delta a[k] & = a[i] - a[-1] + \sum_{k = 0}^{k = i - 1}a[k] - \sum_{k = 0}^{k = i - 1}a[k]\\ 
& = a[i] - a[-1]\\ 
& = a[i]\\ \end{align}$$

- Therefore, a *range sum query* over $\Delta a$ corresponds to a *point query* over $a$.
- Putting these together, we've successfully turned the PURQ problem to RUPQ, which we can solve with segment trees! :exploding_head:

---
<!-- _class: top -->
# RURQ: The Lazy Propagation Technique

- To support *range updates*, let's first look at how we're doing *range queries*.
- What makes range queries really efficient is that we *immediately* return from a node if the query interval contains the entire node interval.

![w:700px center](segtree-rq-4.png)

---
<!-- _class: top -->
# RURQ: The Lazy Propagation Technique

- Could we also somehow do the same thing with range updates? That is, could we somehow *return* from a node right away if the update interval contains the node's interval?

---
<!-- _class: top -->
# RURQ: The Lazy Propagation Technique

- Could we also somehow do the same thing with range updates? That is, could we somehow *return* from a node right away if the update interval contains the node's interval?
- The answer is *yes*; However, this is only possible if we *don't* update all of the child nodes.
- Once we update the entire interval of a node, we need to *defer* updating its children.
- Since we don't propagate updates down the entire tree right away, this is known as the *lazy propagation* technique.

---
<!-- _class: top -->
# RURQ: The Lazy Propagation Technique
- Let's see a basic example of this technique in action.
- Consider the array $a = [3, 1, 4, 1, 5, 9, 2]$. What is the sum of all values in the array?

---
<!-- _class: top -->
# RURQ: The Lazy Propagation Technique
- Let's see a basic example of this technique in action.
- Consider the array $a = [3, 1, 4, 1, 5, 9, 2]$. What is the sum of all values in the array? Yep, it's **24**.
- Now, what if we add $2$ to *every element* in the interval? What happens to the sum now?

---
<!-- _class: top -->
# RURQ: The Lazy Propagation Technique
- Let's see a basic example of this technique in action.
- Consider the array $a = [3, 1, 4, 1, 5, 9, 2]$. What is the sum of all values in the array? Yep, it's **24**.
- Now, what if we add $2$ to *every element* in the interval? What happens to the sum now? The sum is now **38**. You could either update each element and recompute the sum... or realize that you can simply add $2 \times (\text{the number of elements})$ to the previous sum.
- Notice that, TODO

---
<!-- _class: top -->
# RURQ: The Lazy Propagation Technique
- TODO To implement a lazy propagating segtree, we need the following:
    1. An extra `lazy` property per node, representing the *deferred updates* that need to be pushed to the child nodes
- Let us see an example of a lazy propagating segtree in action!

---
<!-- _class: top -->

# Lazy Evaluation in a Broader Scope
- Lazy propagation is an example of a more general technique known as **lazy evaluation**.
- Lazy evaluation is when we defer a computation until its result is needed.
- Lazy evaluation is common with functional programming languages, such as Haskell. However, it is 
- In the context of CompProg, it allows us to define infinite data structures, persistent data structures, 
- The opposite of *lazy* evaluation is *eager* evaluation. This is when we perform a computation right away. This is also more common with imperative programming languages.

---
<!-- _class: top -->

# In Summary...

<br>
<br>
<br>

| | **Point Query** | **Range Query** |
|--|--|--|
| **Point Update** | Random-access DS (eg., Array) | Normal Segtree |
| **Range Update** | Segtree on First-order Differences | Lazy Propagating Segtree |