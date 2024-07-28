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

# Dynamic Programming 1
## Bootcamp Track
## Gabee De Vera

---

<!-- _class: lead -->

# Bitmask DP

---

<!-- _class: top -->

# Bitmask DP

Motivating problem: how many ways are there to tile an $N \times M$ grid with identical $1 \times 2$ and $2 \times 1$ dominoes, where $1 \le M \le 1000$, and $1 \le N \le 10$?

---

<!-- _class: top -->

# Bitmask DP

Motivating problem: how many ways are there to tile an $N \times M$ grid with identical $1 \times 2$ and $2 \times 1$ dominoes, where $1 \le M \le 1000$, and $1 \le N \le 10$?

Note that, since dominoes occupy $2$ grid tiles each, there must be an even number of tiles. Otherwise, it is impossible to tile the grid.

---

<!-- _class: top -->

# Bitmask DP

Motivating problem: how many ways are there to tile an $N \times M$ grid with identical $1 \times 2$ and $2 \times 1$ dominoes, where $1 \le M \le 1000$, and $1 \le N \le 10$?

Note that, since dominoes occupy $2$ grid tiles each, there must be an even number of tiles. Otherwise, it is impossible to tile the grid.

For now, we will consider the case $N = 3$. The general case of $1 \le N \le 10$ will be left as an exercise.

---

<!-- _class: top -->

# Bitmask DP

Let us first try small cases. Consider $N = 3$ and $M = 2$. There are 3 possible tilings, shown below.

![w:1000px center](2-by-3-tilings.png)

---

<!-- _class: top -->

# Bitmask DP

Let us first try small cases. Consider $N = 3$ and $M = 4$. There are 11 possible tilings, shown below.

![w:900px center](4-by-3-tilings.png)

---

<!-- _class: top -->

# Bitmask DP

What about when $N = 3$ and $M = 0$? How many tilings are there?

---

<!-- _class: top -->

<style scoped>
    h2:last-of-type {
        align-self: center;
    }
</style>

# Bitmask DP

What about when $N = 3$ and $M = 0$? How many tilings are there?

<br>
<br>

## There is Exactly ONE Tiling (The Empty Tiling)

---

<!-- _class: top -->

# Bitmask DP

Now, let us try to find a DP solution to this problem.

What DP state should we use? This turns out to be nontrivial, so feel free to think about it for a moment.

---

<!-- _class: top -->

# Bitmask DP

Now, let us try to find a DP solution to this problem.

What DP state should we use? This turns out to be nontrivial, so feel free to think about it for a moment.

---

<!-- _class: top -->

# Bitmask DP

Notice that you can **perform casework on the final column**. You can assume that some tiles in the final column are currently occupied, while some are unoccupied, like so.

![w:600px center](tiling-problem-dp-state.png)

---

<!-- _class: top -->

# Bitmask DP

Then, for each possible state of the final row, we can do some casework to determine how it relates to smaller cases.

![w:600px center](tiling-problem-transition-0.png)

---

<!-- _class: top -->

# Bitmask DP

Then, for each possible state of the final row, we can do some casework to determine how it relates to smaller cases.

![w:600px center](tiling-problem-transition-7.png)

---

<!-- _class: top -->

# Bitmask DP

But now, how do we represent the state of the last column in code? Notice that each tile in the last column could either be **occupied** or **not occupied**.
Thus, there is a **binary choice** per tile of whether or not it should be occupied. We can then associate each ending state with a unique integer, like so.

![w:800px center](tiling-problem-bitmask-representation.png)

This integer is known as a **bitmask**. Bitmasks are a fancy way of storing an array of booleans in a single number.

---

<!-- _class: top -->

# Bitmask DP

Bitmasks have a lot of advantages. For instance, you can use bitmask operations such as bitwise right shift and bitwise AND to extract the $n$th bit of a bitmask.

$$
\begin{align}
3\text{rd bit of }11010_{2} & = \left(11010_{2} >> 3\right) \& 1_{2}\\ 
& = \left(110_{2}\right) \& 1_{2}\\ 
& = 0_{2}
\end{align}
$$

See [this video](https://www.youtube.com/watch?v=xXKL9YBWgCY) for more information on bitmasks.

---

<!-- _class: top -->

# Bitmask DP

Now, all that's left to do is to complete the casework on all other possible states of the last column. You also need to determine the initial values of the DP. This will be left as an exercise for you to accomplish.

![w:600px center](tiling-problem-dp-state.png)

---

<!-- _class: top -->

# Bitmask DP

To generalize to $1 \le N \le 10$, you have to **programmatically** perform your DP transition (please do not do the DP transitions manually ;-;).

The time complexity of this solution is $O(M2^N)$, which should pass.

---

<!-- _class: lead -->

# DP is Powerful

---

<!-- _class: top -->

# Things DP can Do

1. It can turn certain brute force solutions, which may run in exponential time, to something that runs in polynomial time.

---

<!-- _class: top -->

# Things DP can Do

1. It can turn certain brute force solutions, which may run in exponential time, to something that runs in polynomial time.
1. It can turn solutions that run in factorial time to solutions that run in exponential time.

---

<!-- _class: top -->

# Things DP can Do

1. It can turn certain brute force solutions, which may run in exponential time, to something that runs in polynomial time.
1. It can turn solutions that run in factorial time to solutions that run in exponential time.
1. It can compute the $n$th term of a linear recurrence in $O(\log n)$ time. In particular, it allows you to calculate the $n$th Fibonacci number in $O(\log n)$ time. More on this next week!

---

<!-- _class: top -->

# Things DP can Do

1. It can turn certain brute force solutions, which may run in exponential time, to something that runs in polynomial time.
1. It can turn solutions that run in factorial time to solutions that run in exponential time.
1. It can compute the $n$th term of a linear recurrence in $O(\log n)$ time. In particular, it allows you to calculate the $n$th Fibonacci number in $O(\log n)$ time. More on this next week!
1. Etc...

---

<!-- _class: top -->

# Homework

See the [Reboot Page](https://redblazerflame.github.io/reboot-materials/compprog-materials/veteran/19-dp-2/) for your homework this week :smile: