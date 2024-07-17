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

# Sieve Problems
## Veteran Track
## Gabee De Vera

---

<!-- _class: top -->

# Problem 1: Counting Prime Divisors (Easy)
- Create a program to determine the number of prime factors for each number in the range $\left[1, N\right]$. Your program must run in $O(n \log n)$ or $O(n \log \log n)$.
- You may check you program's output against https://oeis.org/A001221. Click the link titled "list" for a table of values to test your program against ^^

---

<!-- _class: top -->

# Problem 2: Squarefree Numbers (Medium)
- Create a program to determine whether each number in the range $\left[1, N\right]$ is squarefree. Your program must run in $O(n \log n)$ or $O(n \log \log n)$.
- Note: A **squarefree** number contains no perfect square factors greater than 1. Note that 1 is squarefree.
- You may check you program's output against https://oeis.org/A008966. Click the link titled "list" for a table of values to test your program against ^^

---

<!-- _class: top -->

# Problem 3: Divisor Listing (Medium)
- Create a program that computes all divisors of all numbers in the range $[1, N]$.
- Specifically, your program will handle $T$ test cases. For each test case, you are given a number $n$ satisfying $1 \le n \le N$. You must print all the divisors of $n$.
- Your target complexity is $O(N \log N + T\tau\left(N\right))$, where $\tau\left(N\right)$ is the maximum number of divisors of any number in $[1, N]$.

---

<!-- _class: top -->

# Problem 4: Mobius Function (Difficult)
- Create a program that computes the value of the mobius function for all numbers in the range $[1, N]$ in $O(N \log N)$ time.
- Hint: You may have to use your solutions from previous problems to do this ^^

---

<!-- _class: top -->

# Problem 5: Simplified Fractions (Very Difficult; Optional but Recommended)
- Given two integers $1 \le i, j \le N$ (not necessarily distinct), what is the probability that the fraction $\frac{i}{j}$ is simplified?
- Output the result $\mod 10^9 + 7$. Note that $\frac{p}{q} \mod 10^9 + 7 \equiv pq^{-1} \mod 10^9 + 7$, where $q^{-1}$ is the modular multiplicative inverse of $q$.
- Your goal is to find something linear or loglinear in $N$
- As an added hint: is there a technique that we could use from this week that could help here? ^^

---

<!-- _class: top -->

# Problem 5: Simplified Fractions (Very Difficult; Optional but Recommended)
- Here are the answers for the first few values of $N$:

| $N$ | Answer |
|--|--|
|1|1|
|2|750000006|
|3|777777784|
|4|187500002|
|5|320000003|

---

<!-- _class: top -->

# Problem 5: Simplified Fractions (Very Difficult; Optional but Recommended)
- Here are the answers for the first few values of $N$:

| $N$ | Answer |
|--|--|
|6|638888894|
|7|714285720|
|8|46875001|
|9|790123463|
|10|910000007|

---

<!-- _class: top -->

# Problem 5: Simplified Fractions (Very Difficult; Optional but Recommended)
- Here are the answers for the first few values of $N$:

| $N$ | Answer |
|--|--|
|30|816666673|
|100|55900001|
|300|436833337|
|1000|770231006|
|100000|927438557|