# Smallest Number With Digit Product Divisible by `t`

## Problem Statement

Given two integers `n` and `t`, find the smallest integer greater than or equal to `n` such that the product of its digits is divisible by `t`.

---

## Intuition

Since the required number must be at least `n`, the simplest approach is to examine every integer starting from `n`.

For each number, compute the product of its digits. If the product is divisible by `t`, that number is the smallest valid answer because the numbers are checked in increasing order.

---

## Approach

### Step 1: Compute the Product of Digits

Create a helper function that repeatedly extracts the last digit using the modulo operator (`% 10`), multiplies it into the running product, and removes the digit using integer division (`/ 10`).

### Step 2: Iterate from `n`

Starting from `n`:

* Calculate the product of its digits.
* If the product is divisible by `t`, return the current number.
* Otherwise, increment the number and repeat.

Since numbers are checked sequentially, the first valid number found is the smallest possible answer.

---

## Algorithm

1. Initialize the current number as `n`.
2. Compute the product of its digits.
3. If the product is divisible by `t`, return the current number.
4. Otherwise, increment the number by one.
5. Repeat until a valid number is found.

---

## Correctness

The algorithm checks every integer in increasing order beginning from `n`.

* If a number does not satisfy the divisibility condition, it is skipped.
* The first number whose digit product is divisible by `t` is returned immediately.

Because every candidate is considered in ascending order, no smaller valid number can be missed. Hence, the returned value is the smallest valid number.

---

## Complexity Analysis

Let `d` be the number of digits in the current number.

For each candidate:

* Computing the digit product takes **O(d)** time.

If `k` numbers are checked before finding the answer:

* **Time Complexity:** **O(k × d)**
* **Space Complexity:** **O(1)**

---

## Key Concepts

* Brute Force
* Simulation
* Digit Manipulation
* Number Theory
